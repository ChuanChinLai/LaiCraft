#include "ItemStack.h"

LaiEngine::ItemStack::ItemStack(const Material & material, int amount) : m_pMaterial(&material), m_numInStack(amount)
{
}

int LaiEngine::ItemStack::Add(int amount)
{
	m_numInStack += amount;

	if (m_numInStack > m_pMaterial->maxStackSize)
	{
		int leftOver = m_numInStack - m_pMaterial->maxStackSize;
		m_numInStack = m_pMaterial->maxStackSize;
		return leftOver;
	}
	else
	{
		return 0;
	}
}

void LaiEngine::ItemStack::Remove()
{
	m_numInStack--;
	if (m_numInStack == 0)
	{
		m_pMaterial = &Material::NOTHING;
	}
}

int LaiEngine::ItemStack::GetNumInStack() const
{
	return m_numInStack;
}

const LaiEngine::Material & LaiEngine::ItemStack::GetMaterial() const
{
	return *m_pMaterial;
}
