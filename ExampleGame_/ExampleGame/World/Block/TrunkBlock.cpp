#include "TrunkBlock.h"

LaiEngine::TrunkBlock::TrunkBlock()
{
	m_texCord_Top    = { 1, 2 };
	m_texCord_Bottom = { 1, 2 };
	m_texCord_Sides  = { 2, 2 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = true;
}

void LaiEngine::TrunkBlock::LoadFromLuaFile(std::string file)
{
}
