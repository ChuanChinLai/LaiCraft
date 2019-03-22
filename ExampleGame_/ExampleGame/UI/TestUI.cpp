#include "TestUI.h"

#include <Engine/Font/Font.h>
#include <Engine/Utility/Timer.h>

#include <ExampleGame/LaiCraft/LaiCraftGame.h>

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
	m_flying = "Is Flying";
}

void LaiEngine::TestUI::Update()
{
	m_text = std::to_string(Timer::FPS());
}

void LaiEngine::TestUI::Release()
{

}

void LaiEngine::TestUI::Draw()
{
	glDisable(GL_CULL_FACE);

	static glm::vec3 color = { 0.5f, 0.8f, 0.2f };
	m_pFont->Draw(m_text, 25.0f, 25.0f, 1.0f, color);

	if (m_pGameInstance->IsCharacterFlying())
	{
		m_pFont->Draw(m_flying, 600.0f, 25.0f, 1.0f, {1, 0, 0});
	}
}

std::thread LaiEngine::TestUI::UpdateWithThread()
{
	return std::thread(&TestUI::Update, this);
}