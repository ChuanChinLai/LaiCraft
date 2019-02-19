#pragma once

#include <Engine/Game/IGameInstance.h>

namespace LaiEngine
{
	class LaiCraftGame : public IGameInstance
	{
	public:

		static LaiCraftGame* Instance();
		static void Delete();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

	private:

		static LaiCraftGame* m_instance;

		bool m_bIsGameRunning = false;

	};
}