#include "GameEngine.h"

#include <Engine/Scene/SceneManager.h>
#include <Engine/Utility/Timer.h>
#include <ExampleGame/Scene/GamingScene.h>
#include <ExampleGame/LaiCraft/LaiCraftGame.h>
#include <ExampleGame/UI/TestUI.h>

#include <Engine/Font/Font.h>

#include <SFML/Graphics.hpp>
#include <glad/glad.h>


LaiEngine::GameEngine::GameEngine(std::string title) : Engine(title)
{

}

bool LaiEngine::GameEngine::Init()
{
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
	}
	catch (std::runtime_error& error) 
	{
		std::cout << error.what() << std::endl;
	}

	return true;
}



void LaiEngine::GameEngine::GameLoop()
{
	Timer timer;

	sf::RenderWindow* pRenderWindow = GetRenderWindow();
	SceneManager* pSceneManager = GetSceneManager();
	pSceneManager->SetWindow(pRenderWindow);

	m_bIsGameRunning = pRenderWindow->isOpen();

	while (m_bIsGameRunning)
	{
		auto deltaTime = timer.dt();

		pSceneManager->Update(deltaTime);
		pSceneManager->InputProcess(pRenderWindow);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pSceneManager->Draw(pRenderWindow);

		pRenderWindow->display();

		HandleEvents();

		timer.Update();
	}
}

void LaiEngine::GameEngine::Release()
{

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
