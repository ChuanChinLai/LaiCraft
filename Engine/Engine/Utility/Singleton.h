#pragma once

#include "NonCopyable.h"
#include "NonMovable.h"

namespace LaiEngine
{
	class Singleton : public NonMovable, public NonCopyable
	{

	};
}