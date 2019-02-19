#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <SFML/Graphics.hpp>
#include <glad/glad.h>
#include <glm/vec2.hpp>

namespace LaiEngine
{
	class BasicTexture : public NonCopyable
	{
	public:
		BasicTexture() = default;
		BasicTexture(const std::string& file);
		~BasicTexture();

		void Init(const std::string& file);
		void Bind() const;
		void Release();

		static std::vector<glm::vec2> GetTextureCord(const glm::ivec2& cord); 

	private:

		void LoadFromImage(const sf::Image& image);
		GLuint m_textureId = 0;
	};
}