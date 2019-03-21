#include "TreeGenerator.h"

#include "StructureBuilder.h"

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>


void LaiEngine::MakeOakTree(Chunk * chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
{
	StructureBuilder builder;

	int h = rand.intInRange(4, 7);
	int leafSize = 2;

	int newY = h + y;
	builder.Fill(x - leafSize, x + leafSize, z - leafSize, z + leafSize, newY, BlockType::LEAF);
	builder.Fill(x - leafSize, x + leafSize, z - leafSize, z + leafSize, newY - 1, BlockType::LEAF);

	for (int32_t zLeaf = -leafSize + 1; zLeaf <= leafSize - 1; zLeaf++)
	{
		builder.AddBlock(x, newY + 1, z + zLeaf, BlockType::LEAF);
	}

	for (int32_t xLeaf = -leafSize + 1; xLeaf <= leafSize - 1; xLeaf++)
	{
		builder.AddBlock(x + xLeaf, newY + 1, z, BlockType::LEAF);
	}

	builder.MakeColumn(x, y, z, h, BlockType::TRUNK);
	builder.Build(chunk);
}

void LaiEngine::MakePalmTree(Chunk * chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
{
	StructureBuilder builder;

	int height = rand.intInRange(7, 9);
	int diameter = rand.intInRange(4, 6);

	for (int xLeaf = -diameter; xLeaf <= diameter; xLeaf++)
	{
		builder.AddBlock(xLeaf + x, y + height, z, BlockType::LEAF);
	}
	for (int zLeaf = -diameter; zLeaf <= diameter; zLeaf++)
	{
		builder.AddBlock(x, y + height, zLeaf + z, BlockType::LEAF);
	}

	builder.AddBlock(x, y + height - 1, z + diameter, BlockType::LEAF);
	builder.AddBlock(x, y + height - 1, z - diameter, BlockType::LEAF);
	builder.AddBlock(x + diameter, y + height - 1, z, BlockType::LEAF);
	builder.AddBlock(x - diameter, y + height - 1, z, BlockType::LEAF);
	builder.AddBlock(x, y + height + 1, z, BlockType::LEAF);

	builder.MakeColumn(x, y, z, height, BlockType::TRUNK);
	builder.Build(chunk);
}

namespace LaiEngine
{
	void makeCactus1(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		builder.MakeColumn(x, z, y, rand.intInRange(4, 7), BlockType::CACTUS);
		builder.Build(chunk);
	}

	void makeCactus2(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		int height = rand.intInRange(6, 8);
		builder.MakeColumn(x, y, z, height, BlockType::CACTUS);

		int stem = height / 2;

		builder.MakeRowX(x - 2, x + 2, stem + y, z, BlockType::CACTUS);
		builder.AddBlock(x - 2, stem + y + 1, z, BlockType::CACTUS);
		builder.AddBlock(x - 2, stem + y + 2, z, BlockType::CACTUS);
		builder.AddBlock(x + 2, stem + y + 1, z, BlockType::CACTUS);

		builder.Build(chunk);
	}


	void makeCactus3(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		int height = rand.intInRange(6, 8);
		builder.MakeColumn(x, y, z, height, BlockType::CACTUS);

		int stem = height / 2;

		builder.MakeRowZ(z - 2, z + 2, x, stem + y, BlockType::CACTUS);
		builder.AddBlock(x, stem + y + 1, z - 2, BlockType::CACTUS);
		builder.AddBlock(x, stem + y + 2, z - 2, BlockType::CACTUS);
		builder.AddBlock(x, stem + y + 1, z + 2, BlockType::CACTUS);

		builder.Build(chunk);
	}
}



void LaiEngine::MakeCactus(Chunk * chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
{
	int cac = rand.intInRange(0, 2);

	switch (cac)
	{
	case 0:
		makeCactus1(chunk, rand, x, y, z);
		break;

	case 1:
		makeCactus2(chunk, rand, x, y, z);
		break;

	case 2:
		makeCactus3(chunk, rand, x, y, z);
		break;
	}
}
