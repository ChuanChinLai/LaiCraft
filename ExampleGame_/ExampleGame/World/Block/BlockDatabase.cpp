#include "BlockDatabase.h"

#include "BlockData.h"
#include "IBlock.h"
#include "GrassBlock.h"
#include "GravelBlock.h"
#include "SandBlock.h"
#include "DirtBlock.h"
#include "WaterBlock.h"
#include "TrunkBlock.h"
#include "LeafBlock.h"
#include "CactusBlock.h"

#include <cassert>


LaiEngine::BlockDatabase* LaiEngine::BlockDatabase::m_pInstance = nullptr;

LaiEngine::BlockDatabase::BlockDatabase()
{
	m_texture.Init("Assets/Textures/DefaultPack.png");
	m_texture.Bind();

	m_blocks = { nullptr };
}

LaiEngine::BlockDatabase::~BlockDatabase()
{
	for (auto& block : m_blocks)
	{
		if (block != nullptr)
		{
			delete block;
		}
	}
}

LaiEngine::BlockDatabase* LaiEngine::BlockDatabase::Get()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new BlockDatabase;
	}

	return m_pInstance;
}

void LaiEngine::BlockDatabase::Release()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
	}
}


LaiEngine::IBlock * LaiEngine::BlockDatabase::GetBlock(const BlockType& type)
{
	const int index = static_cast<int>(type);
	auto& blocks = BlockDatabase::m_pInstance->m_blocks;

	if (blocks[index] == nullptr)
	{
		switch (type)
		{
		case LaiEngine::BlockType::Air:
			return nullptr;

		case LaiEngine::BlockType::Grass:
			blocks[index] = new GrassBlock;
			break;

		case LaiEngine::BlockType::Gravel:
			blocks[index] = new GravelBlock;
			break;

		case LaiEngine::BlockType::Sand:
			blocks[index] = new SandBlock;
			break;

		case LaiEngine::BlockType::Dirt:
			blocks[index] = new DirtBlock;
			break;

		case LaiEngine::BlockType::Water:
			blocks[index] = new WaterBlock;
			break;

		case LaiEngine::BlockType::Trunk:
			blocks[index] = new TrunkBlock;
			break;

		case LaiEngine::BlockType::Leaf:
			blocks[index] = new LeafBlock;
			break;

		case LaiEngine::BlockType::Cactus:
			blocks[index] = new CactusBlock;
			break;

		default:
			break;
		}
	}

	return blocks[index];
}

LaiEngine::BasicTexture* LaiEngine::BlockDatabase::GetTexture()
{
	if (m_pInstance == nullptr)
	{
		BlockDatabase::Get();
	}

	return &(m_pInstance->m_texture);
}
