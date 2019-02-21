#include "LaiCraftGame.h"

#include <ExampleGame/Renderer/RenderingSystem.h>

#include <ExampleGame/UI/TestUI.h>



LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::m_sInstance = nullptr;

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::Instance()
{
	if (m_sInstance == nullptr)
	{
		m_sInstance = new LaiCraftGame();
	}

	return m_sInstance;
}

void LaiEngine::LaiCraftGame::Delete()
{
	if (m_sInstance != nullptr)
	{
		delete m_sInstance;
		m_sInstance = nullptr;
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
