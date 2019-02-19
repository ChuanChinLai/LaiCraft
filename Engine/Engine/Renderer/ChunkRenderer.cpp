#include "ChunkRenderer.h"

#include <Engine/GameObject/Camera.h>

#include <ExampleGame_/ExampleGame/World/Block/ChunkBlock.h>
#include <ExampleGame_/ExampleGame/World/Block/IBlock.h>
#include <ExampleGame_/ExampleGame/World/Block/BlockDatabase.h>

#include <vector>



void LaiEngine::ChunkRenderer::Draw()
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_shader.UseProgram();
	m_shader.SetViewMat(Camera::Get()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Get()->GetProjectedMatrix());

	//glm::mat4 m;
	//m_shader.SetModelMat(m);

	for (int i = 0; i < static_cast<int>(BlockType::NUM_TYPES); i++)
	{
		BlockType type = static_cast<BlockType>(i);

		if (type == BlockType::Water) continue;

		IBlock* block = BlockDatabase::GetBlock(type);

		if (block != nullptr)
		{
			block->Draw();
		}
	}


	//for (auto& object : m_blocks)
	//{
	//	glm::mat4 matrix;

	//	matrix = glm::rotate(matrix, glm::radians(0.0f), { 1, 0, 0 });
	//	matrix = glm::rotate(matrix, glm::radians(0.0f), { 0, 1, 0 });
	//	matrix = glm::rotate(matrix, glm::radians(0.0f), { 0, 0, 1 });

	//	matrix = glm::translate(matrix, object->GetPosition());

	//	m_shader.SetModelMat(matrix);

	//	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_model.GetIndexCount()), GL_UNSIGNED_INT, nullptr);
	//}
}

