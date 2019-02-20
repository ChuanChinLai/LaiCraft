#pragma once

#include <SFML/Graphics.hpp>

namespace LaiEngine
{
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

	private:

		LaiCraftGame() = default;

		static LaiCraftGame* m_pInstance;

		RenderingSystem* m_pRenderingSystem = nullptr;
		TestUI* m_pTestUI = nullptr;

	};
}