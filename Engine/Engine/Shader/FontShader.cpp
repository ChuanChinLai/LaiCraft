#include "FontShader.h"

LaiEngine::FontShader::FontShader(const std::string & vertexFile, const std::string & fragmentFile) : Shader(vertexFile, fragmentFile)
{
	GetUniforms();
}

void LaiEngine::FontShader::SetColor(const glm::vec3 & color)
{
	SetUniformValue(m_locationTextColor, color);
}

void LaiEngine::FontShader::SetProjectedMat(const glm::mat4 & matrix)
{
	SetUniformValue(m_locationProjectedMat, matrix);
}

void LaiEngine::FontShader::GetUniforms()
{
	UseProgram();

	m_locationTextColor = glGetUniformLocation(m_programId, "textColor");
	m_locationProjectedMat = glGetUniformLocation(m_programId, "projectedMat");
}
