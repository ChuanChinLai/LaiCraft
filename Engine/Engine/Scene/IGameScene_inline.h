#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

namespace LaiEngine
{
	inline IGameScene::IGameScene(SceneManager * sceneManager) : m_pSceneManager(sceneManager)
	{

	}

	inline IGameScene::~IGameScene()
	{

	}

}