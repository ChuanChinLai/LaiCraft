#pragma once

#include <Engine/Engine.h>
#include <Engine/Renderer/MainRenderer.h>

namespace LaiEngine
{
	class GameEngine : public Engine
	{
	public:

		GameEngine(const std::string title);

		bool Init() override;
		void GameLoop() override;
		void Release() override;

		static float s_timeElapsed;

	private:
		void HandleEvents() override;
		
		MainRenderer* m_pRenderer;	
	}; 
}