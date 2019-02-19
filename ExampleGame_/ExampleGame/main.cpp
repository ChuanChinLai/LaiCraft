#include <SFML/Graphics.hpp>

#include "LaiCraft/GameEngine.h"


int main()
{
	{
		LaiEngine::GameEngine game("LaiCraft");
		game.Init();
		game.GameLoop();
		game.Release();
	}

//#if defined _DEBUG
	_CrtDumpMemoryLeaks();
//#endif // _DEBUG


	return 0;
}