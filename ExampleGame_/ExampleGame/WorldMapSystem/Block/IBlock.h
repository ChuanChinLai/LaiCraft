#pragma once

#include <Engine/Utility/NonCopyable.h>
#include <Engine/Model/Model.h>

#include <glm/vec2.hpp>
#include <cyCodeBase/cyTriMesh.h>

#include <vector>
#include <string>

namespace LaiEngine
{
	class IBlock : public NonCopyable
	{

	public:

		IBlock();
		virtual ~IBlock();

		void Add(const glm::vec3& position);
		void Draw();

		size_t GetIndexCount() const;

		bool IsCollidable() const;

	protected:

		virtual void LoadFromLuaFile(std::string file) = 0;

		void LoadFaceTop(Mesh& mesh);
		void LoadFaceBottom(Mesh& mesh);
		void LoadFaceSides(Mesh& mesh);

		void BindInstanceBuffer();

	protected:

		Model       m_model;
		cy::TriMesh m_meshLoader;
		glm::ivec2  m_texCord_Top;
		glm::ivec2  m_texCord_Bottom;
		glm::ivec2  m_texCord_Sides;

		std::vector<glm::vec3> m_locations;
		GLuint                 m_instanceBufferId;
		bool                   m_isCollidable;
	};

}