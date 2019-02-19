#include "SkyboxShader.h"

LaiEngine::SkyboxShader::SkyboxShader(const std::string & vertexFile, const std::string & fragmentFile) : Shader(vertexFile, fragmentFile)
{
	GetUniforms();
}

void LaiEngine::SkyboxShader::SetViewMat(glm::mat4 matrix)
{
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;

	SetUniformValue(m_locationViewMat, matrix);
}

void LaiEngine::SkyboxShader::SetProjectedMat(const glm::mat4 & matrix)
{
	SetUniformValue(m_locationProjectedMat, matrix);
}

void LaiEngine::SkyboxShader::GetUniforms()
{
	UseProgram();

	m_locationViewMat      = glGetUniformLocation(m_programId, "viewMat");
	m_locationProjectedMat = glGetUniformLocation(m_programId, "projectedMat");
}
