#include "LaiCraftGame.h"

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::m_instance = nullptr;

LaiEngine::LaiCraftGame* LaiEngine::LaiCraftGame::Instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new LaiCraftGame();
	}

	return m_instance;
}

void LaiEngine::LaiCraftGame::Delete()
{
	if (m_instance != nullptr)
	{
		delete m_instance; 
		m_instance = nullptr;
	}
}

void LaiEngine::LaiCraftGame::Init()
{

}

void LaiEngine::LaiCraftGame::Update()
{

}

void LaiEngine::LaiCraftGame::Release()
{

}
