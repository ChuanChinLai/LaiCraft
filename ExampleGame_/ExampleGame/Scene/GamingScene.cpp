#include "GamingScene.h"

#include <Engine/GameObject/Camera.h>
#include <ExampleGame/LaiCraft/LaiCraftGame.h>

LaiEngine::GamingScene::GamingScene(SceneManager * pSceneManager) : IGameScene(pSceneManager)
{

};

LaiEngine::GamingScene::~GamingScene()
{
	LaiCraftGame::Instance()->Delete();
}

void LaiEngine::GamingScene::Init()
{
	LaiCraftGame::Instance()->Init();
}

void LaiEngine::GamingScene::Update(float dt)
{
	LaiCraftGame::Instance()->Update(dt);
}

void LaiEngine::GamingScene::Release()
{
	LaiCraftGame::Instance()->Release();
}

void LaiEngine::GamingScene::Draw(sf::RenderWindow* window)
{
	LaiCraftGame::Instance()->Draw(window);
}

void LaiEngine::GamingScene::InputProcess(sf::RenderWindow* window)
{
	LaiCraftGame::Instance()->InputProcess(window);
}
