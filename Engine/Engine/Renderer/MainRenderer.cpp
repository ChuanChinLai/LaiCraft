#include "MainRenderer.h"

void LaiEngine::MainRenderer::Draw()
{
	m_chunkRenderer.Draw();
	m_waterRenderer.Draw();

	m_skyboxRenderer.Draw();
}

void LaiEngine::MainRenderer::DrawUI(sf::RenderWindow* window)
{
	m_uiRenderer.Draw(window);
}
