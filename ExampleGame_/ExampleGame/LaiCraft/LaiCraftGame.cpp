#include "LaiCraftGame.h"

#include <ExampleGame/CharacterSystem/CharacterSystem.h>
#include <ExampleGame/RenderingSystem/RenderingSystem.h>

#include <ExampleGame/UI/TestUI.h>

#include <chrono>
#include <iostream>
#include <thread>

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
	m_pCharacterSystem = new CharacterSystem(this);

	m_pTestUI = new TestUI(this);
}

void LaiEngine::LaiCraftGame::Update()
{
	m_pRenderingSystem->Update();
	m_pCharacterSystem->Update();

	m_pTestUI->Update();

	//m_threads.push_back(m_pRenderingSystem->UpdateWithThread());
	//m_threads.push_back(m_pTestUI->UpdateWithThread());

	//for (auto& thread : m_threads)
	//{
	//	if (thread.joinable()) 
	//	{
	//		thread.join();
	//	}
	//}

	//m_threads.clear();
}

void LaiEngine::LaiCraftGame::Release()
{
	if (m_pRenderingSystem != nullptr)
	{
		delete m_pRenderingSystem;
	}

	if (m_pCharacterSystem != nullptr)
	{
		delete m_pCharacterSystem;
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

void LaiEngine::LaiCraftGame::InputProcess(sf::RenderWindow * window)
{
	m_pCharacterSystem->InputProcess(window);
}

void LaiEngine::LaiCraftGameTest::Init()
{
	m_pRenderingSystem = new RenderingSystem(this);
	m_pCharacterSystem = new CharacterSystem(this);
}
