#pragma once

#include <string>

using Block_t = uint8_t;

namespace LaiEngine
{
	enum class BlockType : Block_t
	{
		Air = 0,

		Cactus,
		Dirt,
		Grass,
		Gravel,
		Leaf,
		Sand,
		Trunk,

		Water,
		NUM_TYPES
	};
}