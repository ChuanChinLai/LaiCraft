#include "CharacterSystem.h"

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

void LaiEngine::CharacterSystem::Update()
{
	Camera::Instance()->Update();
}

void LaiEngine::CharacterSystem::Release()
{
}

void LaiEngine::CharacterSystem::InputProcess(sf::RenderWindow * window)
{
	m_character.HandleInput(window);
}

std::thread LaiEngine::CharacterSystem::UpdateWithThread()
{
	return std::thread();
}
