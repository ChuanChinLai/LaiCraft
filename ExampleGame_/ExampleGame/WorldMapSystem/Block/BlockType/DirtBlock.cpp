#include "DirtBlock.h"

LaiEngine::DirtBlock::DirtBlock()
{
	m_texCord_Top    = { 2, 4 };
	m_texCord_Bottom = { 2, 4 };
	m_texCord_Sides  = { 2, 4 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = true;
}

void LaiEngine::DirtBlock::LoadFromLuaFile(std::string file)
{

}
