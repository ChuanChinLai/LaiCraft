#pragma once

#include <SFML/Graphics.hpp>

#include <thread>
#include <vector>

namespace LaiEngine
{
	class CharacterSystem;
	class RenderingSystem;
	class TestUI;

	class LaiCraftGame
	{
	public:

		static LaiCraftGame* Instance();
		static void Delete();

		void Init();
		void Update();
		void Release();

		void Draw(sf::RenderWindow* window);
		void InputProcess(sf::RenderWindow* window);

	protected:

		LaiCraftGame() = default;

		static LaiCraftGame* m_sInstance;

		RenderingSystem* m_pRenderingSystem = nullptr;
		CharacterSystem* m_pCharacterSystem = nullptr;

		TestUI* m_pTestUI = nullptr;

		std::vector<std::thread> m_threads;
	};


	class LaiCraftGameTest : public LaiCraftGame
	{
		void Init();
	};
}