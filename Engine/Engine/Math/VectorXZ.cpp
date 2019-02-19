#include "VectorXZ.h"

bool LaiEngine::operator==(const VectorXZ & lhs, const VectorXZ & rhs) noexcept
{
	return (lhs.x == rhs.x) && (lhs.z == rhs.z);
}
