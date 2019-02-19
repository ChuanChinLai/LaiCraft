#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace sf
{
	class RenderWindow;
}

namespace LaiEngine
{
	class SceneManager;
	class MainRenderer; 

	class IGameScene
	{
	public:

		IGameScene(SceneManager* sceneManager);
		virtual ~IGameScene();

		virtual void Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Release() = 0;
		
		virtual void SubmitDataToBeRendered(MainRenderer* renderer) = 0;

		virtual void HandleInput(sf::RenderWindow* window) = 0;

	protected:
		SceneManager*	m_pSceneManager;
	};
}

#include "IGameScene_inline.h"