#include "ItemSystem.h"

#include <Engine/Math/Ray.h>

#include <ExampleGame/WorldMapSystem/Block/ChunkBlock.h>
#include <ExampleGame/CharacterSystem/Character.h>
#include <ExampleGame/LaiCraft/LaiCraftGame.h>
#include <ExampleGame/WorldMapSystem/World/World.h>

#include <glm/vec3.hpp>
#include <iostream>


LaiEngine::ItemSystem::ItemSystem(LaiCraftGame * pGameInstance): IGameSystem(pGameInstance)
{
	Init();
}

LaiEngine::ItemSystem::~ItemSystem()
{
	Release();
}

void LaiEngine::ItemSystem::Init()
{
	for (int i = 0; i < numItems; i++)
	{
		m_items.emplace_back(Material::NOTHING, 0);
	}
}

void LaiEngine::ItemSystem::Update(float dt)
{
	static sf::Clock timer;
	glm::ivec3 lastPosition;

	const auto& character = m_pGameInstance->GetCharacter();
	const auto& world = m_pGameInstance->GetWorld();

	for (Ray ray(character->position, character->rotation); ray.GetLength() < 6.0f; ray.Step(0.05f))
	{
		int x = static_cast<int>(ray.GetEnd().x);
		int y = static_cast<int>(ray.GetEnd().y);
		int z = static_cast<int>(ray.GetEnd().z);

		auto block = world->GetBlock(x, y, z);

		if (block != nullptr)
		{
			if (timer.getElapsedTime().asSeconds() > 0.2)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					timer.restart();

					const auto& material = Material::ToMaterial(block->GetType());
					AddItem(material);
					world->SetBlock(x, y, z, BlockType::AIR);

					break;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					timer.restart();

					auto& stack = m_items[m_heldItem];
					auto& material = stack.GetMaterial();

					if (material.id == Material::ID::Nothing)
					{
						return;
					}
					else
					{
						stack.Remove();
						world->SetBlock(lastPosition.x, lastPosition.y, lastPosition.z, material.ToBlockType());
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

void LaiEngine::ItemSystem::Release()
{
}

void LaiEngine::ItemSystem::InputProcess(sf::RenderWindow * window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_heldItem++;

		if (m_heldItem == static_cast<int>(m_items.size()))
		{
			m_heldItem = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_heldItem--;
		if (m_heldItem == -1)
		{
			m_heldItem = static_cast<int>(m_items.size()) - 1;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		m_heldItem = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		m_heldItem = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		m_heldItem = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		m_heldItem = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		m_heldItem = 4;
	}
}

std::thread LaiEngine::ItemSystem::UpdateWithThread(float dt)
{
	return std::thread([=] { Update(dt);});
}

void LaiEngine::ItemSystem::AddItem(const Material & material)
{
	Material::ID id = material.id;

	for (unsigned i = 0; i < m_items.size(); i++)
	{
		if (m_items[i].GetMaterial().id == id)
		{
			m_items[i].Add(1);
			return;
		}
		else if (m_items[i].GetMaterial().id == Material::ID::Nothing)
		{
			m_items[i] = { material, 1 };
			return;
		}
	}
}

int LaiEngine::ItemSystem::GetHeldItem() const
{
	return m_heldItem;
}

std::string LaiEngine::ItemSystem::GetItemName(const int id) const
{
	return m_items[id].GetMaterial().name;
}

int LaiEngine::ItemSystem::GetNumberOfItem(const int id) const
{
	return m_items[id].GetNumInStack();
}

