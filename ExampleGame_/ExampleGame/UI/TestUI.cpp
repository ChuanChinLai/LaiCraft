#include "TestUI.h"

#include <Engine/Font/Font.h>
#include <Engine/Utility/Timer.h>

#include <iostream>
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
	//std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
	//std::cout << "TestUI Update" << std::endl;
	m_text = std::to_string(Timer::FPS());
}

void LaiEngine::TestUI::Release()
{

}

void LaiEngine::TestUI::Draw()
{
	static glm::vec3 pos = { 0.5, 0.8f, 0.2f };

	m_pFont->Draw(m_text, 25.0f, 25.0f, 1.0f, pos);
}

std::thread LaiEngine::TestUI::UpdateWithThread()
{
	return std::thread(&TestUI::Update, this);
}