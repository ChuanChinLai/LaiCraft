#pragma once

#include <Engine/Utility/NonCopyable.h>

namespace LaiEngine
{
	class GameInstance;

	class IGameSystem : public NonCopyable
	{
	public:

		IGameSystem(GameInstance* pGameInstance) : m_pGameInstance(pGameInstance)
		{

		}

		virtual ~IGameSystem() = default;

		virtual void Init()    = 0;
		virtual void Update()  = 0;
		virtual void Release() = 0;

	protected:

		GameInstance* m_pGameInstance;
	};
}