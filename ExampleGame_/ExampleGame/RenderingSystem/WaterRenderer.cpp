#include "WaterRenderer.h"

#include <Engine/GameObject/Camera.h>
#include <Engine/Utility/Timer.h>

#include <ExampleGame/WorldMapSystem/Block/BlockFactory/BlockFactory.h>
#include <ExampleGame/WorldMapSystem/Block/IBlock.h>

LaiEngine::WaterRenderer::WaterRenderer()
{
	m_texture.Init("Assets/Textures/DefaultPack.png");
}

void LaiEngine::WaterRenderer::Draw(IBlock * block)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_shader.UseProgram();
	m_shader.SetViewMat(Camera::Instance()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Instance()->GetProjectedMatrix());

	m_shader.SetTime(Timer::TimeElapsed());

	m_texture.Bind();

	if (block != nullptr)
	{
		block->Draw();
	}
}
