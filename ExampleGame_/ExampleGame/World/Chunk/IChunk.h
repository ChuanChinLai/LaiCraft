#pragma once

#include <ExampleGame/World/Block/BlockType.h>

namespace LaiEngine
{
	class ChunkBlock;
	class MainRenderer;

	struct IChunk
	{
		virtual ~IChunk() = default;

		virtual void Update() = 0;
		virtual void SubmitDataToBeRendered(MainRenderer* renderer) = 0;

		virtual ChunkBlock* GetBlock(int x, int y, int z) = 0;
		virtual void        SetBlock(int x, int y, int z, BlockType type) = 0;
	};
}