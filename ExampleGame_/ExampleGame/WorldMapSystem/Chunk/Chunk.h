#pragma once

#include <Engine/Utility/Array2D.h>

#include <ExampleGame/WorldMapSystem/Block/ChunkBlock.h>
#include <ExampleGame/WorldMapSystem/WorldConstants.h>

#include <glm/vec2.hpp>
#include <vector>

namespace LaiEngine
{
	class World;
	class ChunkSection;
	class MainRenderer; 
	class TerrainGenerator;

	class Chunk
	{
	public:

		Chunk() = default;
		Chunk(World* world, const glm::ivec2& position);
		~Chunk();

		void Update();
		void Draw();

		const glm::ivec2& GetLocation() const;
		int               GetHeightAt(const int x, const int z) const; 

		ChunkBlock* GetBlock(int x, int y, int z);
		void        SetBlock(int x, int y, int z, const BlockType& type);

		//bool HasLoaded() const noexcept;
		//void Load(TerrainGenerator* generator);

	private:

		void AddSection();
		void AddSectionWithBlock(int blockY);

		bool IsValid(int x, int y, int z) const;

		std::vector<ChunkSection*>  m_chunkSections;
		Array2D<int, CHUNK_SIZE>    m_highestBlocks;

		World*     m_pWorld;
		glm::ivec2 m_position;
		bool       m_isLoaded = false;
	};
}