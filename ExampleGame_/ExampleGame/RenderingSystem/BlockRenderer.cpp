#include "BlockRenderer.h"

#include <Engine/GameObject/Camera.h>
#include <ExampleGame/WorldMapSystem/Block/BlockType/IBlock.h>

#include <vector>

void LaiEngine::BlockRenderer::Draw(IBlock * block)
{
	if (block == nullptr)
		return;

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_shader.UseProgram();
	m_shader.SetViewMat(Camera::Instance()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Instance()->GetProjectedMatrix());

	block->Draw();
}