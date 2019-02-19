#pragma once

#include <External/Lua/Includes.h>

#include <string>

namespace LaiEngine
{
	namespace Lua
	{
		extern      double	GetNumberFromTableByKey(lua_State& io_luaState, std::string key);
		extern std::string	GetStringFromTableByKey(lua_State& io_luaState, std::string key);
	}
}