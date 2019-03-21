#pragma once

#include <ExampleGame/BaseClass/IGameSystem.h>
#include <ExampleGame/WorldMapSystem/Block/BlockType.h>

#include "BlockRenderer.h"
#include "WaterRenderer.h"
#include "SkyboxRenderer.h"

namespace LaiEngine
{
	class LaiCraftGame;

	class RenderingSystem : public IGameSystem
	{
	public:

		RenderingSystem(LaiCraftGame* pGameInstance);
		~RenderingSystem();

		virtual void Init()	override;
		virtual void Update(float dt) override;
		virtual void Release() override;

		std::thread UpdateWithThread(float dt) override;

		void Draw(const BlockType& type);

	private:

		BlockRenderer  m_blockRenderer;
		WaterRenderer  m_waterRenderer;

		SkyboxRenderer m_skyboxRenderer;
	};
}
