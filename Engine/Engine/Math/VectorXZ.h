#pragma once

#include <functional>

namespace LaiEngine
{
	struct VectorXZ
	{
		int x, z;
	};

	bool operator ==(const VectorXZ& lhs, const VectorXZ& rhs) noexcept;
}

namespace std
{
	template<>
	struct hash<LaiEngine::VectorXZ>
	{
		size_t operator()(const LaiEngine::VectorXZ& vect) const noexcept
		{
			std::hash<decltype(vect.x)> hasher;

			auto hash1 = hasher(vect.x);
			auto hash2 = hasher(vect.z);

			return (hash1 ^ hash2) >> 2;
		}
	};
}
