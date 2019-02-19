#pragma once

#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class FPSCounter
	{
	public:
		
		void Update();

	private:

		sf::Clock m_timer;
		unsigned int m_frameCount = 0;
	};
}