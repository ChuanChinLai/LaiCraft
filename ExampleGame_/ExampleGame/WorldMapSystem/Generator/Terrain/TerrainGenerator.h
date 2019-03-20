#pragma once

namespace LaiEngine
{
	class Chunk;

	class TerrainGenerator
	{
	public:
		virtual void GenerateTerrainFor(Chunk* chunk) = 0;
		virtual int  GetMinimumSpawnHeight() const noexcept = 0;

		virtual ~TerrainGenerator() = default;
	};

}