#include "ChunkSection.h"

#include <Engine/Renderer/MainRenderer.h>

#include <ExampleGame/World/Block/BlockDatabase.h>
#include <ExampleGame/World/Block/IBlock.h>

#include <ExampleGame/World/World.h>

#include <ExampleGame/World/Block/GrassBlock.h>
#include <ExampleGame/World/Block/GravelBlock.h>

#include <iostream>

LaiEngine::ChunkSection::ChunkSection(World * world, const glm::ivec3 & position) : m_pWorld(world), m_position(position), m_chunkBlocks(CHUNK_VOLUME, nullptr)
{

}

LaiEngine::ChunkSection::~ChunkSection()
{
	for (auto& chunkBlock : m_chunkBlocks)
	{
		if (chunkBlock != nullptr)
		{
			delete chunkBlock;
		}
	}

	m_chunkBlocks.clear();
}

void LaiEngine::ChunkSection::Update()
{

}

void LaiEngine::ChunkSection::SubmitDataToBeRendered(MainRenderer * renderer)
{
	auto database = BlockDatabase::Get();

	for (auto& block : m_chunkBlocks)
	{
		if (block == nullptr || block->GetType() == BlockType::Air)
		{
			continue;
		}
		database->GetBlock(block->GetType())->Add(block->GetPosition());
		//database->GetBlock(block->GetType());
	}
}

LaiEngine::ChunkBlock* LaiEngine::ChunkSection::GetBlock(int x, int y, int z)
{
	if (!IsValid(x) || !IsValid(y) || !IsValid(z))
	{
		auto position = ToWorldPosition(x, y, z);
		return m_pWorld->GetBlock(position.x, position.y, position.z);
	}

	const auto index = GetIndex(x, y, z);
	return m_chunkBlocks[index];
}

void LaiEngine::ChunkSection::SetBlock(int x, int y, int z, BlockType type)
{
	if (!IsValid(x) || !IsValid(y) || !IsValid(z))
	{
		auto position = ToWorldPosition(x, y, z);
		m_pWorld->SetBlock(position.x, position.y, position.z, type);
		return;
	}

	const auto position = ToWorldPosition(x, y, z);
	const auto index = GetIndex(x, y, z);
	if (m_chunkBlocks[index] == nullptr)
	{
		delete m_chunkBlocks[index];
	}

	ChunkBlock* block = new ChunkBlock(type);
	block->SetPosition(position);
	m_chunkBlocks[index] = block;
}

const glm::ivec3 LaiEngine::ChunkSection::GetPosition() const noexcept
{
	return m_position;
}

glm::ivec3 LaiEngine::ChunkSection::ToWorldPosition(int x, int y, int z) const
{
	return
	{
		m_position.x * CHUNK_SIZE + x,
		m_position.y * CHUNK_SIZE + y,
		m_position.z * CHUNK_SIZE + z
	};
}

int LaiEngine::ChunkSection::GetIndex(int x, int y, int z) const
{
	return  y * CHUNK_AREA + z * CHUNK_SIZE + x;
}

bool LaiEngine::ChunkSection::IsValid(int value) const
{
	return value < CHUNK_SIZE && value >= 0;
}