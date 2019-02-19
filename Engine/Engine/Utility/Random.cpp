#include "Random.h"

LaiEngine::RandomSingleton & LaiEngine::RandomSingleton::Get()
{
	static RandomSingleton instance;
	return instance;
}

LaiEngine::RandomSingleton::RandomSingleton()
{
	m_randomEngine.seed(std::time(nullptr));

	for (int i = 0; i < 5; i++)
	{
		intInRange(i, i * 5);
	}
}