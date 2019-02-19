#pragma once

#include "BlockType.h"

#include <Engine/Utility/Singleton.h>
#include <Engine/Model/Model.h>
#include <Engine/Texture/BasicTexture.h>

#include <unordered_map>
#include <vector>
#include <array>

namespace LaiEngine
{
	class IBlock;

	class BlockDatabase : public Singleton
	{
	public:

		~BlockDatabase();

		static BlockDatabase* Get();
		static void Release();

		static IBlock* GetBlock(const BlockType& type);
		static BasicTexture* GetTexture();

		 std::array<IBlock*, static_cast<size_t>(BlockType::NUM_TYPES)> m_blocks;

	private:

		BlockDatabase();
		BasicTexture m_texture;

		static BlockDatabase* m_pInstance; 
	};
}