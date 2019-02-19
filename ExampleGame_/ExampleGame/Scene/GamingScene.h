#pragma once

#include <Engine/GameObject/Camera.h>
#include <Engine/Scene/IGameScene.h>

#include <ExampleGame/LaiCraft/Player.h>
#include <ExampleGame/World/World.h>

namespace LaiEngine
{
	class GamingScene : public IGameScene
	{
	public:

		GamingScene(SceneManager* pSceneManager);
		~GamingScene();

		void Init()	override;
		void Update(float dt) override;
		void Release() override;

		void SubmitDataToBeRendered(MainRenderer* renderer) override;

		void HandleInput(sf::RenderWindow* window) override;

	private:

		Camera* m_camera;
		Player* m_player; 

		World*  m_pWorld;
	};
}