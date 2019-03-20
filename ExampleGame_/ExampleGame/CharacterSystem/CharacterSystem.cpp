#include "CharacterSystem.h"

#include <Engine/Utility/Timer.h>
#include <Engine/GameObject/Camera.h>

#include <iostream>

LaiEngine::CharacterSystem::CharacterSystem(LaiCraftGame * pGameInstance) : IGameSystem(pGameInstance)
{
	Init();
}

LaiEngine::CharacterSystem::~CharacterSystem()
{
	Release();
}

void LaiEngine::CharacterSystem::Init()
{
	Camera::Instance()->SetGameObject(&m_character);
}

void LaiEngine::CharacterSystem::Update(float dt)
{
	m_character.Update(dt);

	Camera::Instance()->Update();
}

void LaiEngine::CharacterSystem::Release()
{
}

void LaiEngine::CharacterSystem::InputProcess(sf::RenderWindow * window)
{
	m_character.HandleInput(window);
}

std::thread LaiEngine::CharacterSystem::UpdateWithThread(float dt)
{
	return std::thread();
}
