#include "BasicTexture.h"

#include <iostream>

LaiEngine::BasicTexture::BasicTexture(const std::string & file)
{
	//Init(file);
}

LaiEngine::BasicTexture::~BasicTexture()
{
	Release();
}

void LaiEngine::BasicTexture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void LaiEngine::BasicTexture::Release()
{
	try
	{
		if (m_textureId != 0)
		{
			constexpr GLsizei bufferCount = 1;
			glDeleteTextures(bufferCount, &m_textureId);

			const auto errorCode = glGetError();
			if (errorCode != GL_NO_ERROR)
			{
				throw std::runtime_error("OpenGL failed to delete the texture");
			}
			m_textureId = 0;
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

std::vector<glm::vec2> LaiEngine::BasicTexture::GetTextureCord(const glm::ivec2 & cord)
{
	const float xmin = cord.x * 0.2f; 
	const float ymin = cord.y * 0.2f;
	const float xmax = xmin + 0.2f;
	const float ymax = ymin + 0.2f;

	return { {xmin, ymin}, {xmin, ymax}, {xmax, ymax}, {xmax, ymin}, {xmin, ymin}, {xmax, ymax} };
}

void LaiEngine::BasicTexture::Init(const std::string & file)
{
	if (m_textureId != 0)
		return;

	sf::Image image; 

	try
	{
		if (!image.loadFromFile(file))
		{
			throw std::runtime_error("Unable to load BasicTexture: " + file);
		}

		image.flipVertically();

		LoadFromImage(image);
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}

void LaiEngine::BasicTexture::LoadFromImage(const sf::Image & image)
{
	try
	{
		constexpr GLsizei textureCount = 1;
		glGenTextures(textureCount, &m_textureId);
		const auto errorCode = glGetError();
		if (errorCode == GL_NO_ERROR)
		{
			if (m_textureId != 0)
			{
				glBindTexture(GL_TEXTURE_2D, m_textureId);
				const auto errorCode = glGetError();
				if (errorCode != GL_NO_ERROR)
				{
					throw std::runtime_error("OpenGL failed to bind the new texture");
				}
			}
		}
		else
		{
			throw std::runtime_error("OpenGL failed to create a texture");
		}

		const GLint level = 0;
		const GLsizei width = static_cast<GLsizei>(image.getSize().x);
		const GLsizei height = static_cast<GLsizei>(image.getSize().y);
		const GLint border = 0;
		const GLvoid* data = reinterpret_cast<const GLvoid*>(image.getPixelsPtr());

		glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
}
