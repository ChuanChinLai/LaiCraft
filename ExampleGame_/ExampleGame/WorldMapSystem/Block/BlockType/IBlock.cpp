#include "IBlock.h"

#include <Engine/Texture/BasicTexture.h>

LaiEngine::IBlock::IBlock()
{
	glGenBuffers(1, &m_instanceBufferId);
}

LaiEngine::IBlock::~IBlock()
{

}

void LaiEngine::IBlock::Add(const glm::vec3 & position)
{
	m_locations.push_back(position);
}


void LaiEngine::IBlock::Draw()
{
	m_model.BindVAO();
	BindInstanceBuffer();

	const auto numBlocks   = static_cast<GLsizei>(m_locations.size());
	const auto numElements = static_cast<GLsizei>(m_model.GetIndexCount());

	glDrawElementsInstanced(GL_TRIANGLES, numElements, GL_UNSIGNED_INT, nullptr, numBlocks);
	glBindVertexArray(0);

	m_locations.clear();
}

size_t LaiEngine::IBlock::GetIndexCount() const
{
	return m_model.GetIndexCount();
}

bool LaiEngine::IBlock::IsCollidable() const
{
	return m_isCollidable;
}

void LaiEngine::IBlock::LoadFaceTop(Mesh & mesh)
{
	const unsigned int begin = 0;
	const unsigned int end   = 2;

	auto UVs = BasicTexture::GetTextureCord(m_texCord_Top);

	for (unsigned int i = begin; i < end; i++)
	{
		const cy::TriMesh::TriFace&  f = m_meshLoader.F(i);
		const cy::TriMesh::TriFace& fn = m_meshLoader.FN(i);

		//3 points in a face
		for (size_t j = 0; j < 3; j++)
		{
			sVertex vertex;
			mesh.indices.push_back(static_cast<GLuint>(mesh.indices.size()));

			{
				const cy::Point3f& pos = m_meshLoader.V(f.v[j]);
				vertex.Position = { pos.x, pos.y, pos.z };
			}

			{
				const cy::Point3f& nor = m_meshLoader.VN(fn.v[j]);
				vertex.Normal = { nor.x, nor.y, nor.z };
			}

			{
				vertex.UV = UVs.back();
				UVs.pop_back();
			}

			mesh.vertices.push_back(vertex);
		}
	}
}

void LaiEngine::IBlock::LoadFaceBottom(Mesh & mesh)
{
	const unsigned int begin = 2;
	const unsigned int end   = 4;

	auto UVs = BasicTexture::GetTextureCord(m_texCord_Bottom);

	for (unsigned int i = begin; i < end; i++)
	{
		const cy::TriMesh::TriFace&  f = m_meshLoader.F(i);
		const cy::TriMesh::TriFace& fn = m_meshLoader.FN(i);

		//3 points in a face
		for (size_t j = 0; j < 3; j++)
		{
			sVertex vertex;
			mesh.indices.push_back(static_cast<GLuint>(mesh.indices.size()));

			{
				const cy::Point3f& pos = m_meshLoader.V(f.v[j]);
				vertex.Position = { pos.x, pos.y, pos.z };
			}

			{
				const cy::Point3f& nor = m_meshLoader.VN(fn.v[j]);
				vertex.Normal = { nor.x, nor.y, nor.z };
			}

			{
				vertex.UV = UVs.back();
				UVs.pop_back();
			}

			mesh.vertices.push_back(vertex);
		}
	}
}

void LaiEngine::IBlock::LoadFaceSides(Mesh & mesh)
{
	const unsigned int begin = 4;
	const unsigned int end   = m_meshLoader.NF();

	auto UVs = BasicTexture::GetTextureCord(m_texCord_Sides);

	for (unsigned int i = begin; i < end; i++)
	{
		const cy::TriMesh::TriFace&  f = m_meshLoader.F(i);
		const cy::TriMesh::TriFace& fn = m_meshLoader.FN(i);

		//3 points in a face
		for (size_t j = 0; j < 3; j++)
		{
			sVertex vertex;
			mesh.indices.push_back(static_cast<GLuint>(mesh.indices.size()));

			{
				const cy::Point3f& pos = m_meshLoader.V(f.v[j]);
				vertex.Position = { pos.x, pos.y, pos.z };
			}

			{
				const cy::Point3f& nor = m_meshLoader.VN(fn.v[j]);
				vertex.Normal = { nor.x, nor.y, nor.z };
			}

			{
				vertex.UV = UVs.back();
				UVs.pop_back();
			}

			mesh.vertices.push_back(vertex);

			if (UVs.empty())
			{
				UVs = BasicTexture::GetTextureCord(m_texCord_Sides);
			}
		}
	}
}

void LaiEngine::IBlock::BindInstanceBuffer()
{
	const auto numBlocks = m_locations.size();

	if (numBlocks == 0) return;

	glBindBuffer(GL_ARRAY_BUFFER, m_instanceBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * numBlocks, m_locations.data(), GL_STATIC_DRAW);

	constexpr GLuint vertexElementLocation = 3;
	constexpr GLint elementCount = 3;
	constexpr GLboolean notNormalized = GL_FALSE;
	constexpr auto stride = static_cast<GLsizei>(3 * sizeof(float));
	GLvoid* offset = reinterpret_cast<GLvoid*>(0);

	glVertexAttribPointer(vertexElementLocation, elementCount, GL_FLOAT, notNormalized, stride, offset);
	glVertexAttribDivisor(vertexElementLocation, 1); // tell OpenGL this is an instanced vertex attribute.

	const auto errorCode = glGetError();
	if (errorCode == GL_NO_ERROR)
	{
		glEnableVertexAttribArray(vertexElementLocation);
		const GLenum errorCode = glGetError();
		if (errorCode != GL_NO_ERROR)
		{
			std::string message = "OpenGL failed to enable the offset vertex attribute at location: " + vertexElementLocation;
			throw std::runtime_error(message.c_str());
		}
	}
	else
	{
		throw std::runtime_error("OpenGL failed to set the offset vertex attribute at location: " + vertexElementLocation);
	}


	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
