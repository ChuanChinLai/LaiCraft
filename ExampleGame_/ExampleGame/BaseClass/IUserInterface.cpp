#include "IUserInterface.h"

#include <Engine/Font/Font.h>

LaiEngine::IUserInterface::IUserInterface(LaiCraftGame * pGameInstance) : m_pGameInstance(pGameInstance)
{
	m_pFont = Font::Instance();
}

void LaiEngine::IUserInterface::Draw()
{
	m_pFont->Draw(m_text, 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
}
