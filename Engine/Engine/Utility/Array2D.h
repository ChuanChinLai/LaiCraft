#pragma once

#include <array>
#include <algorithm>


namespace LaiEngine
{
	template<typename T, int WIDTH>
	class Array2D
	{
		using Array = std::array<T, WIDTH * WIDTH>;

	public:

		T& Get(int x, int z)
		{
			return m_array[x * WIDTH + z];
		}

		const T& Get(int x, int z) const
		{
			return m_array[x * WIDTH + z];
		}

		T& GetMaxValue()
		{
			return *std::max_element(m_array.begin(), m_array.end());
		}

		void SetAll(T val)
		{
			m_array.fill(val);
		}

	private:
		Array m_array;
	};


}
