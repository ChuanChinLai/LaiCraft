#pragma once

#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class Timer
	{
	public:
		
		void Update();

		static int FPS();
		float dt() const;
	
	private:

		sf::Clock m_timer;
		sf::Clock m_dt;
		sf::Time  m_time;

		static int   s_frameCount;
		static float s_timeElapsed;
	};
}