#pragma once

#include "Material.h"

namespace LaiEngine
{
	class ItemStack
	{
	public:
		ItemStack(const Material& material, int amount);

		int Add(int amount);
		void Remove();

		int GetNumInStack() const;

		const Material& GetMaterial() const;

	private:
		const Material* m_pMaterial = &Material::NOTHING;
		int             m_numInStack = 0;

	};
}