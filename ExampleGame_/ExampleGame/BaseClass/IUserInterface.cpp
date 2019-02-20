#include "IUserInterface.h"

void LaiEngine::IUserInterface::Draw()
{
	m_font.Draw(m_text, 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
}
