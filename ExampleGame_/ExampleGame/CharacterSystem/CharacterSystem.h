#pragma once

#include "Character.h"

#include <ExampleGame/BaseClass/IGameSystem.h>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class LaiCraftGame;

	class CharacterSystem : public IGameSystem
	{
	public:

		CharacterSystem(LaiCraftGame* pGameInstance);
		~CharacterSystem();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

		void InputProcess(sf::RenderWindow* window);

		std::thread UpdateWithThread() override;

	private:

		Character m_character;
	};
}
