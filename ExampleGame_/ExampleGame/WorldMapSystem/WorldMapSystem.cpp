#include "WorldMapSystem.h"

#include <ExampleGame/LaiCraft/LaiCraftGame.h>
#include <ExampleGame/WorldMapSystem/Block/IBlock.h>
#include <ExampleGame/WorldMapSystem/Block/BlockFactory/BlockFactory.h>
#include <ExampleGame/WorldMapSystem/World/World.h>


LaiEngine::WorldMapSystem::WorldMapSystem(LaiCraftGame * pGameInstance) : IGameSystem(pGameInstance)
{
	Init();
}

LaiEngine::WorldMapSystem::~WorldMapSystem()
{
	Release();
}

void LaiEngine::WorldMapSystem::Init()
{
	if (m_pWorld == nullptr)
	{
		m_pWorld = new World(this);
	}

	m_pWorld->SetSpawnPoint(*m_pGameInstance->GetCharacter());
}

void LaiEngine::WorldMapSystem::Update(float dt)
{
	m_pWorld->Update();
}

void LaiEngine::WorldMapSystem::Release()
{
	BlockFactory::Instance()->Delete();

	if (m_pWorld != nullptr)
	{
		delete m_pWorld;
	}
}

std::thread LaiEngine::WorldMapSystem::UpdateWithThread(float dt)
{
	return std::thread();
}


void LaiEngine::WorldMapSystem::Draw()
{
	m_pWorld->Draw();

	for (int i = 0; i < static_cast<int>(BlockType::NUM_TYPES); i++)
	{
		BlockType type = static_cast<BlockType>(i);
		m_pGameInstance->Draw(type);
	}
}

LaiEngine::World* LaiEngine::WorldMapSystem::GetWorld()
{
	return m_pWorld;
}
