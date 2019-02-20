#include "SceneManager.h"
#include "IGameScene.h"

#include <Engine/Renderer/MainRenderer.h>

LaiEngine::SceneManager::~SceneManager()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
		delete m_pCurrentScene;
		m_pCurrentScene = nullptr;
	}
}

void LaiEngine::SceneManager::SetGameScene(IGameScene * i_Scene)
{
	m_bRunBegin = false;

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
		delete m_pCurrentScene;
	}

	m_pCurrentScene = i_Scene;
}

LaiEngine::IGameScene* LaiEngine::SceneManager::GetGameScene()
{
	return m_pCurrentScene;
}


void LaiEngine::SceneManager::Update(float dt)
{
	if (m_pCurrentScene != nullptr && m_bRunBegin == false)
	{
		m_pCurrentScene->Init();
		m_bRunBegin = true;
	}

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Update(dt);
	}
}

void LaiEngine::SceneManager::Draw(sf::RenderWindow* window)
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Draw(window);
	}
}

void LaiEngine::SceneManager::Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
	}
}

void LaiEngine::SceneManager::SetWindow(sf::RenderWindow * window)
{
	m_pWindow = window;
}

void LaiEngine::SceneManager::InputProcess(sf::RenderWindow* window)
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->InputProcess(window);
	}
}
