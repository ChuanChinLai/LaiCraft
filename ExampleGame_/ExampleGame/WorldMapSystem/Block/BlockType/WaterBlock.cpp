#include "WaterBlock.h"

LaiEngine::WaterBlock::WaterBlock()
{
	m_texCord_Top    = { 3, 1 };
	m_texCord_Bottom = { 3, 1 };
	m_texCord_Sides  = { 3, 1 };

	m_meshLoader.LoadFromFileObj("Assets/Models/cube.obj");

	Mesh mesh;

	this->LoadFaceTop(mesh);
	this->LoadFaceBottom(mesh);
	this->LoadFaceSides(mesh);

	m_model.Init(mesh);

	m_isCollidable = false;
}

void LaiEngine::WaterBlock::LoadFromLuaFile(std::string file)
{

}
