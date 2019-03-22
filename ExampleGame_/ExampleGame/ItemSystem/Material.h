#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>

#include <string>

using namespace std;

namespace LaiEngine
{
	class Material : public NonCopyable
	{
	public:
		enum class ID
		{
			Nothing,
			Cactus,
			Dirt,
			Grass,
			Gravel, 
			Leaf,
			Sand,
			Trunk,
		};

		const static Material   NOTHING,
			CACTUS_BLOCK,
			DIRT_BLOCK,
			GRASS_BLOCK,
			GRAVEL_BLOCK,
			LEAF_BLOCK,
			SAND_BLOCK,
			TRUNK_BLOCK;

		Material(Material::ID id, int maxStack, bool isBlock, std::string name);

		BlockType ToBlockType() const;

		static const Material& ToMaterial(BlockType type);

		const Material::ID  id;
		const int           maxStackSize;
		const bool          isBlock;
		const std::string   name;
	};
}

namespace std
{
	template<>
	struct hash<LaiEngine::Material::ID>
	{
		size_t operator()(const LaiEngine::Material::ID& id) const
		{
			std::hash<LaiEngine::Material::ID> hasher;

			return hasher(id);
		}
	};
}