#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>

namespace LaiEngine
{
	class CharacterSystem;
	class RenderingSystem;
	class WorldMapSystem;

	class TestUI;

	class IBlock;

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

		void Draw(IBlock* block);

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