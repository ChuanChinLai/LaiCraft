#pragma once

#include "ItemStack.h"
#include "Material.h"

#include <ExampleGame/BaseClass/IGameSystem.h>
#include <SFML/Graphics.hpp>

#include <vector>

namespace LaiEngine
{
	class LaiCraftGame;

	class ItemSystem : public IGameSystem
	{
	public:

		ItemSystem(LaiCraftGame* pGameInstance);
		~ItemSystem();

		virtual void Init()	override;
		virtual void Update(float dt) override;
		virtual void Release() override;

		void InputProcess(sf::RenderWindow* window);

		std::thread UpdateWithThread(float dt) override;

		void AddItem(const Material& material);

		std::string GetItemName(const int id) const; 
		int GetNumberOfItem(const int id) const;
		int GetHeldItem() const ;

	private:

		std::vector<ItemStack> m_items;
		const int numItems = 5;
		int m_heldItem = 0;
	};
}
