#include "CactusBlock.h"

LaiEngine::CactusBlock::CactusBlock()
{
	m_texCord_Top    = { 2, 0 };
	m_texCord_Bottom = { 2, 0 };
	m_texCord_Sides  = { 4, 1 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = true;
}

void LaiEngine::CactusBlock::LoadFromLuaFile(std::string file)
{
}
