#pragma once

#include <ExampleGame/BaseClass/IUserInterface.h>
#include <SFML/Graphics.hpp>

#include <glm/vec3.hpp>

namespace LaiEngine
{
	class Font;
	class LaiCraftGame;

	class ItemUI : public IUserInterface
	{
	public:

		ItemUI(LaiCraftGame* pGameInstance);
		~ItemUI();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

		virtual void Draw() override;

		std::thread UpdateWithThread() override;

	private:

		glm::vec3 m_color = { 0.5f, 0.8f, 0.2f };
		std::vector<std::pair<std::string, glm::vec2>>  m_itemText;
	};
}