#pragma once

#include <ExampleGame/BaseClass/IGameSystem.h>

#include "BlockRenderer.h"
#include "SkyboxRenderer.h"
#include "QuadRenderer.h"

namespace LaiEngine
{
	class LaiCraftGame;
	class IBlock;

	class RenderingSystem : public IGameSystem
	{
	public:

		RenderingSystem(LaiCraftGame* pGameInstance);
		~RenderingSystem();

		virtual void Init()	override;
		virtual void Update(float dt) override;
		virtual void Release() override;

		std::thread UpdateWithThread(float dt) override;

		void Draw(IBlock* block);
		void Draw(); 

	private:

		BlockRenderer  m_blockRenderer;
		//SkyboxRenderer m_skyboxRenderer;
	};
}
