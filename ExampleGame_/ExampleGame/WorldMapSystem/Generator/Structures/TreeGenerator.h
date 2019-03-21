#pragma once

#include <Engine/Utility/Random.h>

namespace LaiEngine
{
	class Chunk;

	void MakeOakTree(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z);
	void MakePalmTree(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z);
	void MakeCactus(Chunk* chunk, Random<std::minstd_rand>& rand, int x, int y, int z);
}