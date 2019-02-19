#pragma once

#include "IRenderer.h"

#include <Engine/Shader/BasicShader.h>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class UIRenderer
	{
	public:

		UIRenderer();

		void Draw(sf::RenderWindow* window);

	private:

		sf::Font m_font;
		sf::Text text;
	};
}