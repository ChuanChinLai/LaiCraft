#include "GravelBlock.h"

LaiEngine::GravelBlock::GravelBlock()
{
	m_texCord_Top    = { 3, 4 };
	m_texCord_Bottom = { 3, 4 };
	m_texCord_Sides  = { 3, 4 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = true;
}

void LaiEngine::GravelBlock::LoadFromLuaFile(std::string file)
{
}
