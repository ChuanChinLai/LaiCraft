#include "LeafBlock.h"

LaiEngine::LeafBlock::LeafBlock()
{
	m_texCord_Top    = { 1, 1 };
	m_texCord_Bottom = { 1, 1 };
	m_texCord_Sides  = { 1, 1 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = true;
}

void LaiEngine::LeafBlock::LoadFromLuaFile(std::string file)
{
}
