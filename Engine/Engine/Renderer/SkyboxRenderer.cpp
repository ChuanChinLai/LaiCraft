#include "SkyboxRenderer.h"

#include <Engine/GameObject/Camera.h>

#include <glm/mat4x4.hpp>

#include <array>

LaiEngine::SkyboxRenderer::SkyboxRenderer()
{
	BuildSkyboxModel();

	//const std::array<std::string, 6> files = {"dm", "dm", "dt", "db", "dm", "dm"};

	const std::array<std::string, 6> files = {"dm", "dm", "dt", "db", "dm", "dm"};

	m_cubeTexture.Init(files);
}

LaiEngine::SkyboxRenderer::~SkyboxRenderer()
{

}

void LaiEngine::SkyboxRenderer::Draw()
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	m_shader.UseProgram();
	m_shader.SetViewMat(Camera::Get()->GetViewMatrix());
	m_shader.SetProjectedMat(Camera::Get()->GetProjectedMatrix());

	m_model.BindVAO();
	m_cubeTexture.Bind();

	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_model.GetIndexCount()), GL_UNSIGNED_INT, nullptr);
}

void LaiEngine::SkyboxRenderer::BuildSkyboxModel()
{
	cy::TriMesh meshLoader;
	meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	for (unsigned int i = 0; i < meshLoader.NF(); i++)
	{
		const cy::TriMesh::TriFace  f = meshLoader.F(i);

		//3 points in a face
		for (size_t j = 0; j < 3; j++)
		{
			const unsigned int index = f.v[j];

			sVertex vertex;

			mesh.indices.push_back(static_cast<GLuint>(mesh.indices.size()));
			{
				const cy::Point3f& pos = meshLoader.V(f.v[j]);
				vertex.Position = m_size * glm::vec3(pos.x, pos.y, pos.z);
			}
			mesh.vertices.push_back(vertex);
		}
	}

	m_model.Init(mesh);
}
