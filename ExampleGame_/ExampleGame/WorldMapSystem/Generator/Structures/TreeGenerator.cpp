#include "TreeGenerator.h"

#include "StructureBuilder.h"

#include <ExampleGame/World/Block/BlockType.h>

void LaiEngine::MakeOakTree(Chunk * chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
{
	StructureBuilder builder;

	int h = rand.intInRange(4, 7);
	int leafSize = 2;

	int newY = h + y;
	builder.Fill(x - leafSize, x + leafSize, z - leafSize, z + leafSize, newY, BlockType::Leaf);
	builder.Fill(x - leafSize, x + leafSize, z - leafSize, z + leafSize, newY - 1, BlockType::Leaf);

	for (int32_t zLeaf = -leafSize + 1; zLeaf <= leafSize - 1; zLeaf++)
	{
		builder.AddBlock(x, newY + 1, z + zLeaf, BlockType::Leaf);
	}

	for (int32_t xLeaf = -leafSize + 1; xLeaf <= leafSize - 1; xLeaf++)
	{
		builder.AddBlock(x + xLeaf, newY + 1, z, BlockType::Leaf);
	}

	builder.MakeColumn(x, y, z, h, BlockType::Trunk);
	builder.Build(chunk);
}

void LaiEngine::MakePalmTree(Chunk * chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
{
	StructureBuilder builder;

	int height = rand.intInRange(7, 9);
	int diameter = rand.intInRange(4, 6);

	for (int xLeaf = -diameter; xLeaf <= diameter; xLeaf++)
	{
		builder.AddBlock(xLeaf + x, y + height, z, BlockType::Leaf);
	}
	for (int zLeaf = -diameter; zLeaf <= diameter; zLeaf++)
	{
		builder.AddBlock(x, y + height, zLeaf + z, BlockType::Leaf);
	}

	builder.AddBlock(x, y + height - 1, z + diameter, BlockType::Leaf);
	builder.AddBlock(x, y + height - 1, z - diameter, BlockType::Leaf);
	builder.AddBlock(x + diameter, y + height - 1, z, BlockType::Leaf);
	builder.AddBlock(x - diameter, y + height - 1, z, BlockType::Leaf);
	builder.AddBlock(x, y + height + 1, z, BlockType::Leaf);

	builder.MakeColumn(x, y, z, height, BlockType::Trunk);
	builder.Build(chunk);
}

namespace LaiEngine
{
	void makeCactus1(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		builder.MakeColumn(x, z, y, rand.intInRange(4, 7), BlockType::Cactus);
		builder.Build(chunk);
	}

	void makeCactus2(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		int height = rand.intInRange(6, 8);
		builder.MakeColumn(x, y, z, height, BlockType::Cactus);

		int stem = height / 2;

		builder.MakeRowX(x - 2, x + 2, stem + y, z, BlockType::Cactus);
		builder.AddBlock(x - 2, stem + y + 1, z, BlockType::Cactus);
		builder.AddBlock(x - 2, stem + y + 2, z, BlockType::Cactus);
		builder.AddBlock(x + 2, stem + y + 1, z, BlockType::Cactus);

		builder.Build(chunk);
	}


	void makeCactus3(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z)
	{
		StructureBuilder builder;
		int height = rand.intInRange(6, 8);
		builder.MakeColumn(x, y, z, height, BlockType::Cactus);

		int stem = height / 2;

		builder.MakeRowZ(z - 2, z + 2, x, stem + y, BlockType::Cactus);
		builder.AddBlock(x, stem + y + 1, z - 2, BlockType::Cactus);
		builder.AddBlock(x, stem + y + 2, z - 2, BlockType::Cactus);
		builder.AddBlock(x, stem + y + 1, z + 2, BlockType::Cactus);

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
