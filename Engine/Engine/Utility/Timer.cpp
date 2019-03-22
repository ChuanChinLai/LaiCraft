#include "Timer.h"

#include <iostream>

int LaiEngine::Timer::s_frameCount = 0;
int LaiEngine::Timer::s_framePerSecond = 0;
float LaiEngine::Timer::s_timeElapsed = 0.0f;

void LaiEngine::Timer::Update()
{
	s_frameCount++;

	if (m_timer.getElapsedTime().asSeconds() >= 1.0f)
	{
		//std::cout << "FPS: " << s_frameCount << std::endl;
		s_framePerSecond = s_frameCount;
		s_frameCount = 0;
		m_timer.restart();
	}

	m_time = m_dt.restart();
	s_timeElapsed += m_time.asSeconds();
}

int LaiEngine::Timer::FPS()
{
	return s_framePerSecond;
}

float LaiEngine::Timer::TimeElapsed()
{
	return s_timeElapsed;
}

float LaiEngine::Timer::dt() const
{
	return m_time.asSeconds();
}
