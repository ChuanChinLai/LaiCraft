#include "FPSCounter.h"

#include <iostream>

void LaiEngine::FPSCounter::Update()
{
	m_frameCount++;
	if (m_timer.getElapsedTime().asSeconds() >= 1.0f)
	{
		std::cout << "FPS: " << m_frameCount << std::endl;
		m_frameCount = 0;
		m_timer.restart();
	}
}
