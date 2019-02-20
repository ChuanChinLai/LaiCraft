#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <SFML/Graphics.hpp>
#include <glad/glad.h>

#include <string>

namespace LaiEngine
{
	class CubeTexture : public NonCopyable
	{
	public:

		CubeTexture() = default;
		CubeTexture(const std::string& file);
		~CubeTexture();

		void Init(const std::array<std::string, 6>& files);
		void Bind() const;
		void Release();

	private:

		GLuint m_textureId = 0;
	};
}