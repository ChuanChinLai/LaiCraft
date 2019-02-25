#include "Font.h"

#include <iostream>
#include <stdio.h>

#include <glm/gtc/matrix_transform.hpp>

LaiEngine::Font* LaiEngine::Font::s_pInstance = nullptr;

LaiEngine::Font * LaiEngine::Font::Instance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Font;
	}

	return s_pInstance;
}

void LaiEngine::Font::Delete()
{
	if (s_pInstance != nullptr)
	{
		delete s_pInstance;
	}
}

LaiEngine::Font::Font(const std::string& ttfFile)
{
	Init(ttfFile);
}

LaiEngine::Font::~Font()
{
	Release();
}

void LaiEngine::Font::Init(const std::string& ttfFile)
{
	m_shader.UseProgram();
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), 0.0f, static_cast<GLfloat>(800));
	m_shader.SetProjectedMat(projection);

	CreateVAO();
	CreateVBO();

	// All functions return a value different than 0 whenever an error occurred
	if (FT_Init_FreeType(&m_ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	// Load font as face
	if (FT_New_Face(m_ft, ttfFile.c_str(), 0, &m_face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	// Set size to load glyphs as
	FT_Set_Pixel_Sizes(m_face, 0, 48);

	// Disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Load first 128 characters of ASCII set
	for (GLubyte c = 0; c < 128; c++)
	{
		Load(c);
	}

	FT_Done_Face(m_face);
	FT_Done_FreeType(m_ft);
}

void LaiEngine::Font::Release()
{
	ReleaseVAO();
	ReleaseVBO();
	ReleaseTexture();
}

void LaiEngine::Font::Draw(const std::string& text, GLfloat x, GLfloat y, GLfloat scale, const glm::vec3& color)
{
	// Set OpenGL options
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Activate corresponding render state	
	m_shader.UseProgram();
	m_shader.SetColor(color);

	glActiveTexture(GL_TEXTURE0);

	BindVAO();

	// Iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		const Laichar& ch = m_characters[*c];

		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;
		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}


void LaiEngine::Font::CreateVAO()
{
	constexpr GLsizei arrayCount = 1;
	glGenVertexArrays(arrayCount, &m_vertexArrayId);

	try
	{
		const auto errorCode = glGetError();

		if (errorCode == GL_NO_ERROR)
		{
			glBindVertexArray(m_vertexArrayId);
			const auto errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to bind a new vertex array");
			}
		}
		else
		{
			throw std::runtime_error("OpenGL failed to get an unused vertex array ID");
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::Font::CreateVBO()
{
	try
	{
		//Create vertex buffer
		constexpr GLsizei bufferCount = 1;
		glGenBuffers(bufferCount, &m_vertexBufferId);
		const auto errorCode = glGetError();

		if (errorCode == GL_NO_ERROR)
		{
			//Bind vertex buffer
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
			auto errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to bind a new vertex buffer");
			}

			//Allocate buffer
			const auto bufferSize = sizeof(GLfloat) * 6 * 4;
			glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(bufferSize), nullptr, GL_DYNAMIC_DRAW);
			errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to allocate the vertex buffer");
			}

			//Initialize vertex format

			const auto stride = static_cast<GLsizei>(4 * sizeof(GLfloat));

			//position x y z
			{
				constexpr GLuint vertexElementLocation = 0;
				constexpr GLint elementCount = 4;
				constexpr GLboolean notNormalized = GL_FALSE;
				GLvoid* offset = reinterpret_cast<GLvoid*>(0);
				glVertexAttribPointer(vertexElementLocation, elementCount, GL_FLOAT, notNormalized, stride, offset);
				const auto errorCode = glGetError();

				if (errorCode == GL_NO_ERROR)
				{
					glEnableVertexAttribArray(vertexElementLocation);
					const GLenum errorCode = glGetError();
					if (errorCode != GL_NO_ERROR)
					{
						std::string message = "OpenGL failed to enable the POSITION vertex attribute at location: " + vertexElementLocation;
						throw std::runtime_error(message.c_str());
					}
				}
				else
				{
					throw std::runtime_error("OpenGL failed to set the POSITION vertex attribute at location: " + vertexElementLocation);
				}
			}
		}
		else
		{
			throw std::runtime_error("OpenGL failed to get an unused vertex buffer ID");
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::Font::ReleaseVAO()
{
	try
	{
		if (m_vertexArrayId != 0)
		{
			// Unbind the vertex array
			glBindVertexArray(0);
			const auto errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to unbind all vertex arrays before cleaning up geometry");
			}
		}

		constexpr GLsizei arrayCount = 1;
		glDeleteVertexArrays(arrayCount, &m_vertexArrayId);
		const auto errorCode = glGetError();
		if (errorCode != GL_NO_ERROR)
		{
			throw std::runtime_error("OpenGL failed to delete the vertex array");
		}
		m_vertexArrayId = 0;
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::Font::ReleaseVBO()
{
	try
	{
		if (m_vertexBufferId != 0)
		{
			constexpr GLsizei bufferCount = 1;
			glDeleteBuffers(bufferCount, &m_vertexBufferId);
			const auto errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to delete the vertex buffer");
			}
			m_vertexBufferId = 0;
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::Font::ReleaseTexture()
{
	try
	{
		for (auto& pair : m_characters)
		{
			auto& id = pair.second.TextureID;

			if (id != 0)
			{
				constexpr GLsizei bufferCount = 1;
				glDeleteTextures(bufferCount, &id);

				const auto errorCode = glGetError();
				if (errorCode != GL_NO_ERROR)
				{
					throw std::runtime_error("OpenGL failed to delete the texture");
				}
				id = 0;
			}
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::Font::Load(const GLubyte& c)
{
	// Load character glyph 
	if (FT_Load_Char(m_face, c, FT_LOAD_RENDER))
	{
		std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
		return;
	}

	glGenTextures(1, &m_textureId);
	glBindTexture(GL_TEXTURE_2D, m_textureId);
	glTexImage2D
	(
		GL_TEXTURE_2D,
		0,
		GL_RED,
		m_face->glyph->bitmap.width,
		m_face->glyph->bitmap.rows,
		0,
		GL_RED,
		GL_UNSIGNED_BYTE,
		m_face->glyph->bitmap.buffer
	);
	// Set texture options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Now store character for later use
	Laichar character =
	{
		glm::ivec2(m_face->glyph->bitmap.width, m_face->glyph->bitmap.rows),
		glm::ivec2(m_face->glyph->bitmap_left, m_face->glyph->bitmap_top),
		m_face->glyph->advance.x,
		m_textureId
	};

	m_characters.insert(std::pair<GLchar, Laichar>(c, character));
}

void LaiEngine::Font::BindVAO() const
{
	glBindVertexArray(m_vertexArrayId);
}
