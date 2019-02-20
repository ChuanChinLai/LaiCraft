#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <Engine/Font/Font.h>

namespace LaiEngine
{
	class LaiCraftGame;

	class IUserInterface : public NonCopyable
	{
	public:

		IUserInterface(LaiCraftGame* pGameInstance) : m_pGameInstance(pGameInstance)
		{

		}

		virtual ~IUserInterface() = default;

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Release() = 0;

		virtual void Draw();

	protected:

		LaiCraftGame* m_pGameInstance;
		std::string m_text;
		Font m_font;
	};
}