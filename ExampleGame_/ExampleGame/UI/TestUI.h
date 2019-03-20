#pragma once

#include <ExampleGame/BaseClass/IUserInterface.h>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class LaiCraftGame;

	class TestUI : public IUserInterface
	{
	public:

		TestUI(LaiCraftGame* pGameInstance);
		~TestUI();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

		virtual void Draw() override;

		std::thread UpdateWithThread() override;
	};
}
