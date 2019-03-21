#pragma once

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>

#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>

namespace LaiEngine
{
	class CharacterSystem;
	class RenderingSystem;
	class WorldMapSystem;

	class TestUI;

	class Character;
	class IBlock;
	class World;

	class LaiCraftGame
	{
	public:

		static LaiCraftGame* Instance();
		static void Delete();

		void Init();
		void Update(float dt);
		void Release();

		void Draw(sf::RenderWindow* window);
		void InputProcess(sf::RenderWindow* window);


		//public functions for IGameSystem:
		Character* GetCharacter();
		World*     GetWorld();

		void Draw(const BlockType& type);

	protected:

		LaiCraftGame() = default;

		static LaiCraftGame* s_pInstance;

		CharacterSystem* m_pCharacterSystem = nullptr;
		RenderingSystem* m_pRenderingSystem = nullptr;
		WorldMapSystem*  m_pWorldMapSystem  = nullptr;

		TestUI* m_pTestUI = nullptr;

		std::vector<std::thread> m_threads;
	};
}