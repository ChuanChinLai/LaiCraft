#include "LaiCraftGame.h"

#include <ExampleGame/CharacterSystem/CharacterSystem.h>
#include <ExampleGame/RenderingSystem/RenderingSystem.h>
#include <ExampleGame/WorldMapSystem/WorldMapSystem.h>

#include <ExampleGame/UI/TestUI.h>

#include <chrono>
#include <iostream>
#include <thread>

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::s_pInstance = nullptr;

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::Instance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new LaiCraftGame();
	}

	return s_pInstance;
}

void LaiEngine::LaiCraftGame::Delete()
{
	if (s_pInstance != nullptr)
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}
}

void LaiEngine::LaiCraftGame::Init()
{
	m_pRenderingSystem = new RenderingSystem(this);
	m_pCharacterSystem = new CharacterSystem(this);
	m_pWorldMapSystem  = new WorldMapSystem(this);




	m_pTestUI = new TestUI(this);
}

void LaiEngine::LaiCraftGame::Update(float dt)
{
	m_pCharacterSystem->Update(dt);

	m_pWorldMapSystem->Update(dt);
	m_pRenderingSystem->Update(dt);

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

	if (m_pWorldMapSystem != nullptr)
	{
		delete m_pWorldMapSystem;
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
	m_pWorldMapSystem->Draw();

//	m_pRenderingSystem->Draw();

	m_pTestUI->Draw();
}

void LaiEngine::LaiCraftGame::InputProcess(sf::RenderWindow * window)
{
	m_pCharacterSystem->InputProcess(window);
}

LaiEngine::Character* LaiEngine::LaiCraftGame::GetCharacter()
{
	return m_pCharacterSystem->GetCharacter();
}

LaiEngine::World* LaiEngine::LaiCraftGame::GetWorld()
{
	return m_pWorldMapSystem->GetWorld();
}

void LaiEngine::LaiCraftGame::Draw(const BlockType& type)
{
	if (m_pRenderingSystem != nullptr)
	{
		m_pRenderingSystem->Draw(type);
	}
}
