#pragma once

#include <Engine/Utility/NonCopyable.h>

namespace LaiEngine
{
	class LaiCraftGame;

	class IGameSystem : public NonCopyable
	{
	public:

		IGameSystem(LaiCraftGame* pGameInstance) : m_pGameInstance(pGameInstance)
		{

		}

		virtual ~IGameSystem() = default;

		virtual void Init()    = 0;
		virtual void Update()  = 0;
		virtual void Release() = 0;

	protected:

		LaiCraftGame* m_pGameInstance;
	};
}