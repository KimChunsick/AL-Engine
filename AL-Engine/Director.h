#pragma once

#include "DXUT\Core\DXUT.h"
#include "Types.h"
#include "Scene.h"

namespace AL
{
	class Director : public Singleton<Director>
	{
	public:
		Director();
		virtual ~Director() {}

		void Update();
		void ReplaceScene(Scene* scene);

		Vector2 GetScreenSize();

	public:
		static LPD3DXSPRITE sprite;

	private:
		void UpdateGame();
		void SetNextScene();

	private:
		Scene* _currentScene;
		Scene* _nextScene;
		
	};
}