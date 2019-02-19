#pragma once

#include <Engine/Model/Mesh.h>
#include <Engine/Utility/NonCopyable.h>

namespace LaiEngine
{
	class Model : public NonCopyable
	{
	public:
		Model() = default;
		Model(const Mesh& mesh);
		~Model();

		Model(Model&& other);
		Model& operator= (Model&& other);

		void Init(const Mesh& mesh);
		void BindVAO() const;
		void Release();

		size_t GetIndexCount() const;

	private:

		void CreateVAO();
		void CreateVBO(const std::vector<sVertex>& vertices);
		void CreateEBO(const std::vector<GLuint>& indices);

		void ReleaseVAO();
		void ReleaseVBO();
		void ReleaseEBO();

		// A vertex array encapsulates the vertex data as well as the vertex input layout
		GLuint m_vertexArrayId = 0;

		// A vertex buffer holds the data for each vertex
		GLuint m_vertexBufferId = 0;
		GLuint m_indexBufferId = 0;

		size_t m_indexCount = 0;
	};
}