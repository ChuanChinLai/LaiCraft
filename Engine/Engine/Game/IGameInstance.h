#pragma once

#include <Engine/Utility/NonCopyable.h>

namespace LaiEngine
{
	class IGameInstance : public NonCopyable
	{
	public:

		IGameInstance() = default;
		virtual ~IGameInstance() = default;

		virtual void Init()    = 0;
		virtual void Update()  = 0;
		virtual void Release() = 0;
	};
}