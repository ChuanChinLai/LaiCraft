#pragma once

#include <ExampleGame/BaseClass/IGameSystem.h>

namespace LaiEngine
{
	class LaiCraftGame;
	class IBlock;
	class World;

	class WorldMapSystem : public IGameSystem
	{
	public:

		WorldMapSystem(LaiCraftGame* pGameInstance);
		~WorldMapSystem();

		virtual void Init()	override;
		virtual void Update(float dt) override;
		virtual void Release() override;

		std::thread UpdateWithThread(float dt) override;

		void Draw();

	private:

		World* m_pWorld = nullptr;

	};
}
