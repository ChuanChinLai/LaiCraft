#include "GamingScene.h"

#include <Engine/GameObject/Camera.h>
#include <ExampleGame/LaiCraft/LaiCraftGame.h>

LaiEngine::GamingScene::GamingScene(SceneManager * pSceneManager) : IGameScene(pSceneManager)
{

};

LaiEngine::GamingScene::~GamingScene()
{
	LaiCraftGame::Instance()->Delete();
}

void LaiEngine::GamingScene::Init()
{
	LaiCraftGame::Instance()->Init();

	//if (m_player == nullptr)
	//{
	//	m_player = new Player();
	//}

	//m_camera = Camera::Get();
	//m_camera->SetGameObject(m_player);


	//if (m_pWorld == nullptr)
	//{
	//	m_pWorld = new World(m_player);
	//}
}

void LaiEngine::GamingScene::Update(float dt)
{
	LaiCraftGame::Instance()->Update(dt);
	//m_pWorld->Update();
	//m_player->Update(m_pWorld, dt);
	//m_camera->Update();
}

void LaiEngine::GamingScene::Release()
{
	LaiCraftGame::Instance()->Release();

	//if (m_player != nullptr)
	//{
	//	delete m_player;
	//}

	//if (m_pWorld != nullptr)
	//{
	//	delete m_pWorld;
	//}
}

void LaiEngine::GamingScene::Draw(sf::RenderWindow* window)
{
	LaiCraftGame::Instance()->Draw(window);
}

void LaiEngine::GamingScene::InputProcess(sf::RenderWindow* window)
{
	LaiCraftGame::Instance()->InputProcess(window);
	//if (window != nullptr)
	//{
	//	m_player->HandleInput(window);
	//}

	//static sf::Clock timer;
	//glm::ivec3 lastPosition;

	//for (Ray ray(m_player->position, m_player->rotation); ray.GetLength() < 6.0f; ray.Step(0.05f))
	//{
	//	int x = static_cast<int>(ray.GetEnd().x);
	//	int y = static_cast<int>(ray.GetEnd().y);
	//	int z = static_cast<int>(ray.GetEnd().z);

	//	auto block = m_pWorld->GetBlock(x, y, z);

	//	if (block != nullptr)
	//	{
	//		if (timer.getElapsedTime().asSeconds() > 0.2)
	//		{
	//			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//			{
	//				timer.restart();

	//				const auto& material = Material::ToMaterial(block->GetType());
	//				std::cout << material.id << std::endl;
	//				m_player->AddItem(material);
	//				m_pWorld->SetBlock(x, y, z, BlockType::Air);

	//				break;
	//			}
	//			else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	//			{
	//				timer.restart();

	//				auto& stack = m_player->GetHeldItems();
	//				auto& material = stack.GetMaterial();

	//				if (material.id == Material::ID::Nothing)
	//				{
	//					return;
	//				}
	//				else
	//				{
	//					stack.Remove();
	//					m_pWorld->SetBlock(lastPosition.x, lastPosition.y, lastPosition.z, material.ToBlockType());
	//					break;
	//				}

	//				//m_pWorld->SetBlock(x, y, z, BlockType::Grass);

	//				break;
	//			}
	//		}
	//	}
	//	lastPosition = ray.GetEnd();
	//}
}
