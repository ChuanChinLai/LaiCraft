#pragma once

#include <string>

using Block_t = uint8_t;

namespace LaiEngine
{
	enum class BlockType : Block_t
	{
		AIR = 0,

		CACTUS,
		DIRT,
		GRASS,
		GRAVEL,
		LEAF,
		SAND,
		TRUNK,

		WATER,
		NUM_TYPES
	};
}