#pragma once

#include <Engine/Game/IGameSystem.h>

namespace LaiEngine
{
	class RenderingSystem : public IGameSystem
	{
	public:

		RenderingSystem(GameInstance* pGameInstance);

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;
	};
}
