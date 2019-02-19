#include "CubeTexture.h"

#include <iostream>
#include <array>

LaiEngine::CubeTexture::CubeTexture(const std::string & file)
{
}

LaiEngine::CubeTexture::~CubeTexture()
{
	Release();
}

void LaiEngine::CubeTexture::Init(const std::array<std::string, 6>& files)
{
	try
	{
		constexpr GLsizei textureCount = 1;
		glGenTextures(textureCount, &m_textureId);
		glActiveTexture(GL_TEXTURE0);
		const auto errorCode = glGetError();
		if (errorCode == GL_NO_ERROR)
		{
			if (m_textureId != 0)
			{
				glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureId);
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
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}

	for (int i = 0; i < 6; i++)
	{
		sf::Image image;

		std::string fullPath = "Assets/Textures/" + files[i] + ".png";

		if (!image.loadFromFile(fullPath))
		{
//			throw std::runtime_error("Unable to load CubeTexture Part: " + fullPath);
		}

		const GLenum  target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + i;
		const GLint   level  = 0;
		const GLsizei width  = static_cast<GLsizei>(image.getSize().x);
		const GLsizei height = static_cast<GLsizei>(image.getSize().y);
		const GLint   border = 0;
		const GLvoid* data   = reinterpret_cast<const GLvoid*>(image.getPixelsPtr());

		glTexImage2D(target, level, GL_RGBA, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

}

void LaiEngine::CubeTexture::Bind() const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureId);
}

void LaiEngine::CubeTexture::Release()
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
