#include "StructureBuilder.h"

#include <ExampleGame/WorldMapSystem/Chunk/Chunk.h>

void LaiEngine::StructureBuilder::Build(Chunk * chunk)
{
	for (auto& block : m_blocks)
	{
		chunk->SetBlock(block.x, block.y, block.z, block.type);
	}
}

void LaiEngine::StructureBuilder::MakeColumn(int x, int y, int z, int height, BlockType type)
{
	for (int i = y; i < y + height; i++)
	{
		AddBlock(x, i, z, type);
	}
}

void LaiEngine::StructureBuilder::MakeRowX(int xStart, int xEnd, int y, int z, BlockType type)
{
	for (int x = xStart; x <= xEnd; x++)
	{
		AddBlock(x, y, z, type);
	}
}

void LaiEngine::StructureBuilder::MakeRowZ(int zStart, int zEnd, int x, int y, BlockType type)
{
	for (int z = zStart; z <= zEnd; z++)
	{
		AddBlock(x, y, z, type);
	}
}

void LaiEngine::StructureBuilder::Fill(int xStart, int xEnd, int zStart, int zEnd, int y, BlockType type)
{
	for (int x = xStart; x <= xEnd; x++)
	{
		for (int z = zStart; z <= zEnd; z++)
		{
			AddBlock(x, y, z, type);
		}
	}
}

void LaiEngine::StructureBuilder::AddBlock(int x, int y, int z, BlockType type)
{
	m_blocks.emplace_back(type, x, y, z);
}
