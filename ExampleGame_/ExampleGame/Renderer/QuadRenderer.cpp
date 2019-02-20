#include "QuadRenderer.h"

#include <Engine/GameObject/Camera.h>
#include <Engine/Math/Matrix.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

LaiEngine::QuadRenderer::QuadRenderer()
{ 
	Init();
}

void LaiEngine::QuadRenderer::Init()
{
	m_texture.Init("Assets/Textures/Test.png");

	Mesh mesh;

	{
		{
			sVertex vertex;
			vertex.Position = { 0.5f, 0.5f, 0 };
			vertex.UV = { 1.0f, 1.0f };
			mesh.vertices.push_back(vertex);
		}

		{
			sVertex vertex;
			vertex.Position = { 0.5f, -0.5f, 0 };
			vertex.UV = { 1.0f, 0.0f };
			mesh.vertices.push_back(vertex);
		}

		{
			sVertex vertex;
			vertex.Position = { -0.5f, -0.5f, 0 };
			vertex.UV = { 0.0f, 0.0f };
			mesh.vertices.push_back(vertex);
		}

		{
			sVertex vertex;
			vertex.Position = { -0.5f, 0.5f, 0 };
			vertex.UV = { 0.0f, 1.0f };
			mesh.vertices.push_back(vertex);
		}
	}

	mesh.indices = { 0, 3, 1, 1, 3, 2 };

	m_quadModel.Init(mesh);
}

void LaiEngine::QuadRenderer::Draw()
{
	m_quadModel.BindVAO();
	m_shader.UseProgram();
	m_texture.Bind();

	m_shader.SetViewMat(Camera::Instance()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Instance()->GetProjectedMatrix());

	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_quadModel.GetIndexCount()), GL_UNSIGNED_INT, nullptr);
}