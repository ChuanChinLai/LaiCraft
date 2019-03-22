#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace LaiEngine
{
	class SceneManager;

	class IGameScene
	{
	public:

		IGameScene(SceneManager* sceneManager);
		virtual ~IGameScene();

		virtual void Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Release() = 0;
		
		virtual void Draw(sf::RenderWindow* window) = 0;
		virtual void InputProcess(sf::RenderWindow* window, sf::Event& event) = 0;

	protected:
		SceneManager*	m_pSceneManager;
	};
}

#include "IGameScene_inline.h"