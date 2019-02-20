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

void LaiEngine::RenderingSystem::Update()
{

}

void LaiEngine::RenderingSystem::Release()
{

}

void LaiEngine::RenderingSystem::Draw()
{
	m_quadRenderer.Draw();
//	m_skyboxRenderer.Draw();
}
