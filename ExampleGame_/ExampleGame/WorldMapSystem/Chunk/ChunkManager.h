#pragma once

#include <Engine/Math/VectorXZ.h>

#include <unordered_map>

namespace LaiEngine
{
	class Chunk;
}

using ChunkMap = std::unordered_map<LaiEngine::VectorXZ, LaiEngine::Chunk*>;

namespace LaiEngine
{
	class World;
	class TerrainGenerator;

	class ChunkManager
	{
	public:
		ChunkManager(World* world);
		~ChunkManager();

		ChunkMap&   Get();

		Chunk*      GetChunk(int x, int z);
		void        Add(int x, int z);

		TerrainGenerator* GetTerrainGenerator() const;

		bool IsValid(int x, int z) const;

		void Load(const int x, const int z);
		void Unload(const int x, const int z);

	private:

		ChunkMap          m_chunks;
		World*            m_pWorld;
		TerrainGenerator* m_pTerrainGenerator;
	};

}