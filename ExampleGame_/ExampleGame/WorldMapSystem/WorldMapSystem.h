#pragma once

#include <ExampleGame/BaseClass/IGameSystem.h>

namespace LaiEngine
{
	class LaiCraftGame;
	class IBlock;

	class WorldMapSystem : public IGameSystem
	{
	public:

		WorldMapSystem(LaiCraftGame* pGameInstance);
		~WorldMapSystem();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

		std::thread UpdateWithThread() override;

		void Draw(IBlock* block);
		void Draw();

	private:

	};
}
