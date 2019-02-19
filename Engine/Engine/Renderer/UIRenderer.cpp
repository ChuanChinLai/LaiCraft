#include "UIRenderer.h"

#include <iostream>

LaiEngine::UIRenderer::UIRenderer()
{
	if (!m_font.loadFromFile("Assets/Fonts/rs.ttf"))
	{
		std::cout << "ERROR";
	}


	// select the font
	text.setFont(m_font);

	// set the string to display
	text.setString("Hello world");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void LaiEngine::UIRenderer::Draw(sf::RenderWindow* window)
{
	if (window != nullptr)
	{
		window->draw(text);
	}
}
