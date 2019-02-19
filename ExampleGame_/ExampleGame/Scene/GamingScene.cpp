#include "GamingScene.h"

#include <Engine/Renderer/MainRenderer.h>
#include <Engine/Math/Ray.h>

LaiEngine::GamingScene::GamingScene(SceneManager * pSceneManager) : IGameScene(pSceneManager), m_camera(nullptr), m_player(nullptr), m_pWorld(nullptr)
{

};

LaiEngine::GamingScene::~GamingScene()
{
	
}

void LaiEngine::GamingScene::Init()
{
	if (m_player == nullptr)
	{
		m_player = new Player();
	}

	m_camera = Camera::Get();
	m_camera->SetGameObject(m_player);


	if (m_pWorld == nullptr)
	{
		m_pWorld = new World(m_player);
	}
}

void LaiEngine::GamingScene::Update(float dt)
{
	m_pWorld->Update();
	m_player->Update(m_pWorld, dt);
	m_camera->Update();
}

void LaiEngine::GamingScene::Release()
{
	if (m_player != nullptr)
	{
		delete m_player;
	}

	if (m_pWorld != nullptr)
	{
		delete m_pWorld;
	}
}

void LaiEngine::GamingScene::SubmitDataToBeRendered(MainRenderer* renderer)
{
	if (renderer != nullptr)
	{
		m_pWorld->SubmitDataToBeRendered(renderer);
	}
}

void LaiEngine::GamingScene::HandleInput(sf::RenderWindow* window)
{
	if (window != nullptr)
	{
		m_player->HandleInput(window);
	}

	static sf::Clock timer;
	glm::ivec3 lastPosition;

	for (Ray ray(m_player->position, m_player->rotation); ray.GetLength() < 6.0f; ray.Step(0.05f))
	{
		int x = static_cast<int>(ray.GetEnd().x);
		int y = static_cast<int>(ray.GetEnd().y);
		int z = static_cast<int>(ray.GetEnd().z);

		auto block = m_pWorld->GetBlock(x, y, z);

		if (block != nullptr)
		{
			if (timer.getElapsedTime().asSeconds() > 0.2)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					timer.restart();

					const auto& material = Material::ToMaterial(block->GetType());
					std::cout << material.id << std::endl;
					m_player->AddItem(material);
					m_pWorld->SetBlock(x, y, z, BlockType::Air);

					break;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					timer.restart();

					auto& stack = m_player->GetHeldItems();
					auto& material = stack.GetMaterial();

					if (material.id == Material::ID::Nothing)
					{
						return;
					}
					else
					{
						stack.Remove();
						m_pWorld->SetBlock(lastPosition.x, lastPosition.y, lastPosition.z, material.ToBlockType());
						break;
					}

					//m_pWorld->SetBlock(x, y, z, BlockType::Grass);

					break;
				}
			}
		}
		lastPosition = ray.GetEnd();
	}
}
