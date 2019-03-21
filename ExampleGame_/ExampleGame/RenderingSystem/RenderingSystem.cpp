#include "RenderingSystem.h"

#include <ExampleGame/LaiCraft/LaiCraftGame.h>

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>
#include <ExampleGame/WorldMapSystem/Block/BlockFactory/BlockFactory.h>


LaiEngine::RenderingSystem::RenderingSystem(LaiCraftGame * pGameInstance) : IGameSystem(pGameInstance)
{
	Init();
}

LaiEngine::RenderingSystem::~RenderingSystem()
{
	Release();
}

void LaiEngine::RenderingSystem::Init()
{

}

void LaiEngine::RenderingSystem::Update(float dt)
{
	//std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
	//std::cout << "RenderingSystem Update" << std::endl;
}

void LaiEngine::RenderingSystem::Release()
{

}

std::thread LaiEngine::RenderingSystem::UpdateWithThread(float dt)
{
	//return std::thread();
	return std::thread([=] { Update(dt);});
}

void LaiEngine::RenderingSystem::Draw(const BlockType& type)
{
	IBlock* block = BlockFactory::Get(type);

	if (type == BlockType::WATER)
	{
		m_waterRenderer.Draw(block);
	}
	else
	{
		m_blockRenderer.Draw(block);
	}


	m_skyboxRenderer.Draw();
}
