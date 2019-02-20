#include "LaiCraftGame.h"

#include <ExampleGame/Renderer/RenderingSystem.h>

#include <ExampleGame/UI/TestUI.h>



LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::m_pInstance = nullptr;

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new LaiCraftGame();
	}

	return m_pInstance;
}

void LaiEngine::LaiCraftGame::Delete()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void LaiEngine::LaiCraftGame::Init()
{
	m_pRenderingSystem = new RenderingSystem(this);

	m_pTestUI = new TestUI(this);
}

void LaiEngine::LaiCraftGame::Update()
{
	m_pRenderingSystem->Update();
	m_pTestUI->Update();
}

void LaiEngine::LaiCraftGame::Release()
{
	if (m_pRenderingSystem != nullptr)
	{
		delete m_pRenderingSystem;
	}

	if (m_pTestUI != nullptr)
	{
		delete m_pTestUI;
	}
}

void LaiEngine::LaiCraftGame::Draw(sf::RenderWindow * window)
{
	m_pRenderingSystem->Draw();

	m_pTestUI->Draw();
}
