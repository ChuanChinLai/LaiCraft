#include "TestUI.h"

#include <Engine/Utility/Timer.h>

#include <string>

LaiEngine::TestUI::TestUI(LaiCraftGame * pGameInstance) : IUserInterface(pGameInstance)
{
	Init();
}

LaiEngine::TestUI::~TestUI()
{
	Release();
}

void LaiEngine::TestUI::Init()
{

}

void LaiEngine::TestUI::Update()
{
	std::string fps = std::to_string(Timer::FPS());
	m_text = fps;
}

void LaiEngine::TestUI::Release()
{

}
