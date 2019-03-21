#pragma once

#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class Timer
	{
	public:
		
		void Update();

		float dt() const;
	
		static int   FPS();
		static float TimeElapsed();

	private:

		sf::Clock m_timer;
		sf::Clock m_dt;
		sf::Time  m_time;

		static int   s_frameCount;
		static float s_timeElapsed;
	};
}