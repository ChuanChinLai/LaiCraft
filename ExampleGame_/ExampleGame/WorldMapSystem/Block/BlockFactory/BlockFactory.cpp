
#include "GrassBlock.h"
#include "GravelBlock.h"
#include "SandBlock.h"
#include "DirtBlock.h"
#include "WaterBlock.h"
#include "TrunkBlock.h"
#include "LeafBlock.h"
#include "CactusBlock.h"

#include <cassert>
#include "BlockFactory.h"


LaiEngine::BlockFactory* LaiEngine::BlockFactory::s_pInstance = nullptr;

LaiEngine::BlockFactory::BlockFactory()
{
	m_blocks = { nullptr };
}

LaiEngine::BlockFactory::~BlockFactory()
{
	for (auto& block : m_blocks)
	{
		if (block != nullptr)
		{
			delete block;
		}
	}
}

LaiEngine::BlockFactory* LaiEngine::BlockFactory::Instance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new BlockFactory;
	}

	return s_pInstance;
}

void LaiEngine::BlockFactory::Delete()
{
	if (s_pInstance != nullptr)
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}
}

LaiEngine::IBlock * LaiEngine::BlockFactory::Get(const BlockType& type)
{
	const int index = static_cast<int>(type);
	auto& blocks = BlockFactory::Instance()->m_blocks;

	if (blocks[index] == nullptr)
	{
		switch (type)
		{
		case LaiEngine::BlockType::AIR:
			return nullptr;

		case LaiEngine::BlockType::CACTUS:
			blocks[index] = new CactusBlock;
			break;

		case LaiEngine::BlockType::DIRT:
			blocks[index] = new DirtBlock;
			break;

		case LaiEngine::BlockType::GRASS:
			blocks[index] = new GrassBlock;
			break;

		case LaiEngine::BlockType::GRAVEL:
			blocks[index] = new GravelBlock;
			break;

		case LaiEngine::BlockType::LEAF:
			blocks[index] = new LeafBlock;
			break;

		case LaiEngine::BlockType::SAND:
			blocks[index] = new SandBlock;
			break;

		case LaiEngine::BlockType::TRUNK:
			blocks[index] = new TrunkBlock;
			break;

		case LaiEngine::BlockType::WATER:
			blocks[index] = new WaterBlock;
			break;

		default:
			break;
		}
	}

	return blocks[index];
}

const std::array<LaiEngine::IBlock*, static_cast<size_t>(LaiEngine::BlockType::NUM_TYPES)>& LaiEngine::BlockFactory::GetAll()
{
	return BlockFactory::Instance()->m_blocks;
}
