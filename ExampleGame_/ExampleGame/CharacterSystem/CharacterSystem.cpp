#include "CharacterSystem.h"

#include <Engine/Utility/Timer.h>
#include <Engine/GameObject/Camera.h>

#include <ExampleGame/LaiCraft/LaiCraftGame.h>

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
	if (m_pCharacter == nullptr)
	{
		m_pCharacter = new Character(this);
	}

	Camera::Instance()->SetGameObject(m_pCharacter);
}

void LaiEngine::CharacterSystem::Update(float dt)
{
	m_pCharacter->Update(m_pGameInstance->GetWorld(), dt);

	Camera::Instance()->Update();
}

void LaiEngine::CharacterSystem::Release()
{
	if (m_pCharacter != nullptr)
	{
		delete m_pCharacter;
	}
}

void LaiEngine::CharacterSystem::InputProcess(sf::RenderWindow * window, sf::Event& event)
{
	m_pCharacter->HandleInput(window, event);
}

LaiEngine::Character* LaiEngine::CharacterSystem::GetCharacter() const
{
	return m_pCharacter;
}

bool LaiEngine::CharacterSystem::IsCharacterFlying() const
{
	return m_pCharacter->IsFlying();
}

std::thread LaiEngine::CharacterSystem::UpdateWithThread(float dt)
{
	return std::thread([=] { Update(dt);});
}
