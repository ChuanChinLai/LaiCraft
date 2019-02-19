#pragma once

#include <ExampleGame/World/Block/BlockType.h>
#include <vector>

namespace LaiEngine
{
	class Chunk; 

	class StructureBuilder
	{
		struct Block
		{
			Block(BlockType type, int x, int y, int z) : type(type), x(x), y(y), z(z)
			{ 

			}

			BlockType type;
			int x, y, z;
		};

	public:
		void Build(Chunk* chunk);

		void MakeColumn(int x, int y, int z, int height, BlockType type);
		void MakeRowX(int xStart, int xEnd, int y, int z, BlockType type);
		void MakeRowZ(int zStart, int zEnd, int x, int y, BlockType type);

		void Fill(int xStart, int xEnd, int zStart, int zEnd, int y, BlockType type);
		void AddBlock(int x, int y, int z, BlockType type);

	private:
		std::vector<Block> m_blocks;
	};
}