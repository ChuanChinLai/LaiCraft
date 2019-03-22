#include "IUserInterface.h"

#include <Engine/Font/Font.h>

LaiEngine::IUserInterface::IUserInterface(LaiCraftGame * pGameInstance) : m_pGameInstance(pGameInstance)
{
	m_pFont = Font::Instance();
}

void LaiEngine::IUserInterface::Draw()
{

}
