#include "ItemUI.h"

#include <Engine/Font/Font.h>
#include <ExampleGame/LaiCraft/LaiCraftGame.h>
#include <ExampleGame/ItemSystem/Material.h>

#include <iostream>
#include <string>

LaiEngine::ItemUI::ItemUI(LaiCraftGame * pGameInstance) : IUserInterface(pGameInstance)
{
	Init();
}

LaiEngine::ItemUI::~ItemUI()
{
	Release();
}

void LaiEngine::ItemUI::Init()
{
	for (int i = 0; i < 5; i++)
	{
		std::string text = std::to_string(i);
		glm::vec2 pos = { 25.0f, 50.0f * i + 100.0f };
		m_itemText.push_back(std::make_pair(text, pos));
	}
}

void LaiEngine::ItemUI::Update()
{
	for (int i = 0; i < 5; i++)
	{
		m_itemText[i].first = m_pGameInstance->GetItemString(i);
	}
}

void LaiEngine::ItemUI::Release()
{
}

void LaiEngine::ItemUI::Draw()
{
	glDisable(GL_CULL_FACE);

	for (int i = 0; i < 5; i++)
	{
		const auto& text = m_itemText[i].first;
		const auto& pos = m_itemText[i].second;

		static glm::vec3 color = { 0.5f, 0.8f, 0.2f };
		m_pFont->Draw(text, pos.x, pos.y, 1.0f, color);
	}
}

std::thread LaiEngine::ItemUI::UpdateWithThread()
{
	return std::thread();
}