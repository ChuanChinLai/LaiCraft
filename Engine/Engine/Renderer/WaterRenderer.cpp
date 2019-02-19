#include "WaterRenderer.h"

#include <Engine/GameObject/Camera.h>
#include <ExampleGame_/ExampleGame/LaiCraft/GameEngine.h>

#include <ExampleGame_/ExampleGame/World/Block/ChunkBlock.h>
#include <ExampleGame_/ExampleGame/World/Block/IBlock.h>
#include <ExampleGame_/ExampleGame/World/Block/BlockDatabase.h>

void LaiEngine::WaterRenderer::Draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_shader.UseProgram();
	m_shader.SetViewMat(Camera::Get()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Get()->GetProjectedMatrix());

	m_shader.SetTime(GameEngine::s_timeElapsed);

	{
		IBlock* block = BlockDatabase::GetBlock(BlockType::Water);

		if (block != nullptr)
		{
			block->Draw();
		}
	}

}
