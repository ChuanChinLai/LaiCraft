#include "Chunk.h"

#include <ExampleGame/WorldMapSystem/WorldConstants.h>
#include <ExampleGame/WorldMapSystem/Chunk/ChunkSection.h>
#include <ExampleGame/WorldMapSystem/Generator/Terrain/TerrainGenerator.h>


LaiEngine::Chunk::Chunk(World* world, const glm::ivec2 & position) : m_pWorld(world), m_position(position)
{
	m_highestBlocks.SetAll(0);

	for (int y = 0; y < CHUNK_SECTION; y++)
	{
		ChunkSection* chunkSection = new ChunkSection(world, glm::ivec3(position.x, y, position.y));
		m_chunkSections.push_back(chunkSection);
	}
}

LaiEngine::Chunk::~Chunk()
{
	for (auto& chunkSection : m_chunkSections)
	{
		if (chunkSection != nullptr)
		{
			delete chunkSection;
		}
	}

	m_chunkSections.clear();
}

void LaiEngine::Chunk::Update()
{

}

void LaiEngine::Chunk::Draw()
{
	for (auto& chunkSection : m_chunkSections)
	{
		chunkSection->Draw();
	}
}


const glm::ivec2 & LaiEngine::Chunk::GetLocation() const
{
	return m_position;
}

int LaiEngine::Chunk::GetHeightAt(const int x, const int z) const
{
	return m_highestBlocks.Get(x, z);
}

LaiEngine::ChunkBlock* LaiEngine::Chunk::GetBlock(int x, int y, int z)
{
	if (!IsValid(x, y, z))
	{
		return nullptr;
	}

	const int bY = y % CHUNK_SIZE;

	return m_chunkSections.at(y / CHUNK_SIZE)->GetBlock(x, bY, z);
}

void LaiEngine::Chunk::SetBlock(int x, int y, int z, const BlockType& type)
{
	AddSectionWithBlock(y);

	if (!IsValid(x, y, z))
		return;

	const int bY = y % CHUNK_SIZE;

	m_chunkSections.at(y / CHUNK_SIZE)->SetBlock(x, bY, z, type);

	if (y > m_highestBlocks.Get(x, z))
	{
		m_highestBlocks.Get(x, z) = y;
	}

}

bool LaiEngine::Chunk::HasLoaded() const noexcept
{
	return m_isLoaded;
}

void LaiEngine::Chunk::Load(TerrainGenerator* generator)
{
	if (m_isLoaded) return;

	if (generator != nullptr)
	{
		generator->GenerateTerrainFor(this);
		m_isLoaded = true;
	}
}

void LaiEngine::Chunk::AddSection()
{
	const size_t y = m_chunkSections.size();
	ChunkSection* chunkSection = new ChunkSection(m_pWorld, glm::ivec3(m_position.x, y, m_position.y));
	m_chunkSections.push_back(chunkSection);
}

void LaiEngine::Chunk::AddSectionWithBlock(int blockY)
{
	int index = blockY / CHUNK_SIZE;

	while (static_cast<int>(m_chunkSections.size()) < index + 1)
	{
		AddSection();
	}
}


bool LaiEngine::Chunk::IsValid(int x, int y, int z) const
{
	if (x >= CHUNK_SIZE) return false;
	if (z >= CHUNK_SIZE) return false;

	if (x < 0) return false;
	if (y < 0) return false;
	if (z < 0) return false;

	if (y >= (int)m_chunkSections.size() * CHUNK_SIZE)
	{
		return false;
	}

	return true;
}
