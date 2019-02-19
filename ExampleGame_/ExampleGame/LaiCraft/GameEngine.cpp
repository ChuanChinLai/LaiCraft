#include "GameEngine.h"

#include <Engine/Scene/SceneManager.h>
#include <Engine/Utility/FPSCounter.h>
#include <ExampleGame/Scene/GamingScene.h>
#include <ExampleGame/World/Block/BlockDatabase.h>

#include <SFML/Graphics.hpp>
#include <glad/glad.h>


float LaiEngine::GameEngine::s_timeElapsed = 0.0f;

LaiEngine::GameEngine::GameEngine(std::string title) : Engine(title), m_pRenderer(nullptr)
{

}

bool LaiEngine::GameEngine::Init()
{
	BlockDatabase::Get();

	try
	{
		SceneManager* pSceneManager = GetSceneManager();

		if (pSceneManager != nullptr)
		{
			GamingScene* scene = new GamingScene(pSceneManager);
			pSceneManager->SetGameScene(scene);
		}
		else
		{
			throw std::runtime_error("Failed to initialize the SceneManager");
		}

		m_pRenderer = new MainRenderer();
	}
	catch (std::runtime_error& error) 
	{
		std::cout << error.what() << std::endl;
	}

	return true;
}



void LaiEngine::GameEngine::GameLoop()
{
	sf::Clock timer; 
	sf::Clock dt;
	sf::Time m;

	FPSCounter fpsCounter;

	sf::RenderWindow* pRenderWindow = GetRenderWindow();
	SceneManager* pSceneManager = GetSceneManager();
	pSceneManager->SetWindow(pRenderWindow);

	m_bIsGameRunning = pRenderWindow->isOpen();

	while (m_bIsGameRunning)
	{
		auto deltaTime = timer.restart();

		pSceneManager->Update(deltaTime.asSeconds());
		pSceneManager->HandleInput(pRenderWindow);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pSceneManager->Render(m_pRenderer);

		pRenderWindow->display();

		HandleEvents();

		fpsCounter.Update();

		m = dt.restart();
		s_timeElapsed += m.asSeconds();
	}
}

void LaiEngine::GameEngine::Release()
{
	if (m_pRenderer != nullptr)
	{
		delete m_pRenderer;
	}

	BlockDatabase::Release();
	//Camera::Release();
}

void LaiEngine::GameEngine::HandleEvents()
{
	sf::Event event;

	sf::RenderWindow* pRenderWindow = GetRenderWindow();

	while (pRenderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_bIsGameRunning = false; 
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_bIsGameRunning = false;
		}
	}
}
