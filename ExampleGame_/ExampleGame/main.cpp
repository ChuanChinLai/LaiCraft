#include "LaiCraft/GameEngine.h"

#include <iostream>

int main()
{
	{
		LaiEngine::GameEngine game("LaiCraft");
		game.Init();
		game.GameLoop();
		game.Release();
	}

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG


	return 0;
}