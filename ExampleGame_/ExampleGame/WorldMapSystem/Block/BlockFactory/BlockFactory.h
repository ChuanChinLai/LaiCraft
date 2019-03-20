#pragma once

#include "../BlockType.h"

#include <Engine/Utility/Singleton.h>
#include <Engine/Texture/basictexture.h>

#include <unordered_map>
#include <vector>
#include <array>

namespace LaiEngine
{
	class IBlock;

	class BlockFactory : public Singleton
	{
	public:

		static BlockFactory* Instance();
		static void Delete();

		static IBlock* Get(const BlockType& type);
		static const std::array<IBlock*, static_cast<size_t>(BlockType::NUM_TYPES)>& GetAll();


	private:

		BlockFactory();
		~BlockFactory();

		std::array<IBlock*, static_cast<size_t>(BlockType::NUM_TYPES)> m_blocks;

		static BlockFactory* s_pInstance;
	};
}