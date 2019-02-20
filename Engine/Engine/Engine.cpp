#include "Engine.h"

#include <Engine/Scene/SceneManager.h>

#include <SFML/Graphics.hpp>
#include <glad/glad.h>
#include <iostream>

LaiEngine::Engine::Engine(const std::string title) : m_pRenderWindow(nullptr), m_pSceneManager(nullptr)
{
	m_pRenderWindow = new sf::RenderWindow();

	m_pSceneManager = new SceneManager();

	try
	{
		if (!InitGL(title))
		{
			throw std::runtime_error("Failed to initialize OpenGL");
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}

}

LaiEngine::Engine::~Engine()
{
	if (m_pSceneManager != nullptr)
	{
		delete m_pSceneManager;
	}

	if (m_pRenderWindow != nullptr)
	{
		m_pRenderWindow->close();
		delete m_pRenderWindow;
	}
}

sf::RenderWindow * LaiEngine::Engine::GetRenderWindow() const 
{
	return m_pRenderWindow;
}

LaiEngine::SceneManager * LaiEngine::Engine::GetSceneManager() const
{
	return m_pSceneManager;
}

bool LaiEngine::Engine::InitGL(const std::string title)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;
	settings.stencilBits = 8;


	try
	{
		sf::String sf_title(title.c_str());
		m_pRenderWindow->create({ 800, 800 }, sf_title, sf::Style::Close, settings);

		if (!gladLoadGL())
		{
			throw std::runtime_error("Failed to load OpenGL");
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
		return false;
	}


	glViewport(0, 0, m_pRenderWindow->getSize().x, m_pRenderWindow->getSize().y);

	//glEnable(GL_DEPTH_TEST);

	return true;
}
