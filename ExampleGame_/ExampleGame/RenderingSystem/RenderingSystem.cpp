#include "RenderingSystem.h"

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

void LaiEngine::RenderingSystem::Draw(IBlock * block)
{
	m_blockRenderer.Draw(block);
}

void LaiEngine::RenderingSystem::Draw()
{
//	m_skyboxRenderer.Draw();
}
