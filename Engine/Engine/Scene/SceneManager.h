#pragma once

#include <string>

namespace sf
{
	class RenderWindow;
}

namespace LaiEngine
{
	class IGameScene;
	class MainRenderer; 

	class SceneManager
	{
	public:

		SceneManager() : m_pWindow(nullptr), m_pCurrentScene(nullptr), m_bRunBegin(false)
		{

		};

		~SceneManager();

		void SetGameScene(IGameScene* i_Scene);
		IGameScene* GetGameScene();

		void Update(float dt);
		void Render(MainRenderer* renderer);
		void Release();

		void SetWindow(sf::RenderWindow* window);
		void HandleInput(sf::RenderWindow* window);

	private:

		sf::RenderWindow* m_pWindow;
		IGameScene*       m_pCurrentScene;
		bool 		      m_bRunBegin;
	};
}