#pragma once

#include "ChunkRenderer.h"
#include "WaterRenderer.h"
#include "SkyboxRenderer.h"
#include "UIRenderer.h"

#include <SFML/Graphics.hpp>
#include <glm/vec3.hpp>

namespace LaiEngine
{
	class MainRenderer
	{
	public:

		void Draw();
		void DrawUI(sf::RenderWindow* window);

	private:

		ChunkRenderer  m_chunkRenderer;
		WaterRenderer  m_waterRenderer;
		SkyboxRenderer m_skyboxRenderer;
		UIRenderer     m_uiRenderer;
	};
}