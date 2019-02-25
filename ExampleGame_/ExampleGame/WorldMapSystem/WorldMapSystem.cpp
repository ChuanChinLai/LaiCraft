#include "WorldMapSystem.h"

LaiEngine::WorldMapSystem::WorldMapSystem(LaiCraftGame * pGameInstance) : IGameSystem(pGameInstance)
{
}

LaiEngine::WorldMapSystem::~WorldMapSystem()
{
}

void LaiEngine::WorldMapSystem::Init()
{
}

void LaiEngine::WorldMapSystem::Update()
{
}

void LaiEngine::WorldMapSystem::Release()
{
}

std::thread LaiEngine::WorldMapSystem::UpdateWithThread()
{
	return std::thread();
}

void LaiEngine::WorldMapSystem::Draw(IBlock * block)
{
}

void LaiEngine::WorldMapSystem::Draw()
{
}
