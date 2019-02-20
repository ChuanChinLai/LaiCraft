#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <Engine/Shader/FontShader.h>

#include <glad/glad.h>
#include <glm/vec2.hpp>

// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <map>

namespace LaiEngine
{
	struct Character 
	{
		glm::ivec2 Size;    // Size of glyph
		glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
		GLuint Advance;    // Horizontal offset to advance to next glyph
		GLuint TextureID;   // ID handle of the glyph texture
	};

	class Font : public NonCopyable
	{
	public:
		Font(const std::string& ttfFile = "Assets/Fonts/rs.ttf");

		void Init(const std::string& ttfFile);
		void Release();

		void Draw(const std::string& text, GLfloat x, GLfloat y, GLfloat scale, const glm::vec3& color);

	private:

		void CreateVAO();
		void CreateVBO();

		void ReleaseVAO();
		void ReleaseVBO();
		void ReleaseTexture();

		void Load(const GLubyte& c);
		void BindVAO() const;


		std::map<GLchar, Character> m_characters;
		FT_Library m_ft;
		FT_Face    m_face;
		FontShader m_shader;

		GLuint m_vertexArrayId  = 0;
		GLuint m_vertexBufferId = 0;
		GLuint m_textureId      = 0;
	};
}