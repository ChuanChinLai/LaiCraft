#pragma once

#include <string>

namespace sf
{
	class RenderWindow; 
}

namespace LaiEngine
{
	class SceneManager; 
	class Camera; 

	class Engine
	{
	public:

		Engine(const std::string title);
		virtual ~Engine(); 

		virtual bool Init() = 0;
		virtual void GameLoop() = 0;
		virtual void Release() = 0;

		virtual void HandleEvents() = 0;

		sf::RenderWindow*  GetRenderWindow() const;
		LaiEngine::SceneManager* GetSceneManager() const;


	protected: 

		bool m_bIsGameRunning = false;

	private:

		virtual bool InitGL(std::string title);
		
		sf::RenderWindow*        m_pRenderWindow = nullptr;
		LaiEngine::SceneManager* m_pSceneManager = nullptr;

	};
}