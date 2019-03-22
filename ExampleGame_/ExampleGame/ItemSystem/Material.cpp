#include "Material.h"


const LaiEngine::Material LaiEngine::Material::NOTHING(ID::Nothing, 0, false, "None");

const LaiEngine::Material LaiEngine::Material::CACTUS_BLOCK(ID::Cactus, 99, true, "Cactus Block");
const LaiEngine::Material LaiEngine::Material::DIRT_BLOCK(ID::Dirt, 99, true, "Dirt Block");
const LaiEngine::Material LaiEngine::Material::GRASS_BLOCK(ID::Grass, 99, true, "Grass Block");
const LaiEngine::Material LaiEngine::Material::GRAVEL_BLOCK(ID::Gravel, 99, true, "Gravel Block");
const LaiEngine::Material LaiEngine::Material::LEAF_BLOCK(ID::Leaf, 99, true, "Leaf Block");
const LaiEngine::Material LaiEngine::Material::SAND_BLOCK(ID::Sand, 99, true, "Sand Block");
const LaiEngine::Material LaiEngine::Material::TRUNK_BLOCK(ID::Trunk, 99, true, "Trunk Block");


LaiEngine::Material::Material(Material::ID id, int maxStack, bool isBlock, std::string name) : id(id) , maxStackSize(maxStack) , isBlock(isBlock) , name(name)
{
}

LaiEngine::BlockType LaiEngine::Material::ToBlockType() const
{
	switch (id)
	{
	case Material::ID::Nothing:
		return BlockType::AIR;

	case Material::ID::Cactus:
		return BlockType::CACTUS;

	case Material::ID::Dirt:
		return BlockType::DIRT;

	case Material::ID::Grass:
		return BlockType::GRASS;

	case Material::ID::Gravel:
		return BlockType::GRAVEL;

	case Material::ID::Leaf:
		return BlockType::LEAF;

	case Material::ID::Sand:
		return BlockType::SAND;

	case Material::ID::Trunk:
		return BlockType::TRUNK;

	default:
		return BlockType::NUM_TYPES;
	}
}

const LaiEngine::Material & LaiEngine::Material::ToMaterial(BlockType type)
{
	switch (type)
	{
	case LaiEngine::BlockType::CACTUS:
		return Material::CACTUS_BLOCK;

	case LaiEngine::BlockType::DIRT:
		return Material::DIRT_BLOCK;

	case LaiEngine::BlockType::GRASS:
		return Material::GRASS_BLOCK;

	case LaiEngine::BlockType::GRAVEL:
		return Material::GRAVEL_BLOCK;

	case LaiEngine::BlockType::LEAF:
		return Material::LEAF_BLOCK;

	case LaiEngine::BlockType::SAND:
		return Material::SAND_BLOCK;

	case LaiEngine::BlockType::TRUNK:
		return Material::TRUNK_BLOCK;

	default:
		return Material::NOTHING;
	}
}
