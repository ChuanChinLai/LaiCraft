#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <string>

namespace LaiEngine
{
	class Font;
	class LaiCraftGame;

	class IUserInterface : public NonCopyable
	{
	public:

		IUserInterface(LaiCraftGame* pGameInstance);

		virtual ~IUserInterface() = default;

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Release() = 0;

		virtual void Draw();

	protected:

		LaiCraftGame* m_pGameInstance;
		std::string   m_text;

		Font* m_pFont = nullptr;
	};
}