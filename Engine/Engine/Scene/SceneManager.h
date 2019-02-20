#pragma once

#include <string>

namespace sf
{
	class RenderWindow;
}

namespace LaiEngine
{
	class IGameScene;

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
		void Release();

		void Draw(sf::RenderWindow* window);

		void SetWindow(sf::RenderWindow* window);
		void InputProcess(sf::RenderWindow* window);

	private:

		sf::RenderWindow* m_pWindow;
		IGameScene*       m_pCurrentScene;
		bool 		      m_bRunBegin;
	};
}