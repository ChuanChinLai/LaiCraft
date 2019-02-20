#pragma once

#include <ExampleGame/BaseClass/IGameSystem.h>

#include "SkyboxRenderer.h"
#include "QuadRenderer.h"

namespace LaiEngine
{
	class LaiCraftGame;

	class RenderingSystem : public IGameSystem
	{
	public:

		RenderingSystem(LaiCraftGame* pGameInstance);
		~RenderingSystem();

		virtual void Init()	override;
		virtual void Update() override;
		virtual void Release() override;

		void Draw(); 

	private:

		QuadRenderer   m_quadRenderer; 
		//SkyboxRenderer m_skyboxRenderer;
	};
}
