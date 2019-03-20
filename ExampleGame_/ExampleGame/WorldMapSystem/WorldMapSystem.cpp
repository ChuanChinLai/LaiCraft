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
		m_pWorld = new World();
	}
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

	const auto& blocks = BlockFactory::GetAll();
	
	for (const auto& block : blocks)
	{
		m_pGameInstance->Draw(block);
	}
}
