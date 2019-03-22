#pragma once

#include <Engine/Scene/IGameScene.h>

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

		void Draw(sf::RenderWindow* window) override;
		void InputProcess(sf::RenderWindow* window, sf::Event& event) override;

	private:

		//Camera* m_camera;
		//Player* m_player; 
		//World*  m_pWorld;
	};
}