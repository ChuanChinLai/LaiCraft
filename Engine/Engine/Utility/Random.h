#pragma once

#include "Singleton.h"

#include <random>
#include <ctime>

namespace LaiEngine
{
	class RandomSingleton : public Singleton
	{
	public:
		static RandomSingleton& Get();

		template<typename T>
		T intInRange(T low, T high)
		{
			static_assert(std::is_integral<T>::value, "Not integral type!");
			std::uniform_int_distribution<T> dist(low, high);
			return dist(m_randomEngine);
		}

	private:
		RandomSingleton();

		std::mt19937 m_randomEngine;
	};


	template<typename REngine = std::mt19937>
	class Random
	{
	public:
		Random(int n = std::time(nullptr))
		{
			m_randomEngine.seed(n);
			for (int i = 0; i < 5; i++)
				intInRange(i, i * 5);
		}

		template<typename T>
		T intInRange(T low, T high)
		{
			static_assert(std::is_integral<T>::value, "Not integral type!");
			std::uniform_int_distribution<T> dist(low, high);
			return dist(m_randomEngine);
		}

		void setSeed(int seed)
		{
			m_randomEngine.seed(seed);
		}

	private:
		REngine m_randomEngine;
	};

}