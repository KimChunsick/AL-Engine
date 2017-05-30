#pragma once

#include "DXUT\Core\DXUT.h"
#include "Types.h"
#include "Scene.h"

namespace AL
{
	class Director : public Singleton<Director>
	{
	private:
		Scene* _currentScene;
		Scene* _nextScene;
		static LPD3DXSPRITE _sprite;

	private:
		void UpdateGame();
		void SetNextScene();

	public:
		Director();
		virtual ~Director() {}

		void Update();
		void ReplaceScene(Scene* const scene);
		static void Init();

		const Vector2 GetScreenSize() const;
		const static LPD3DXSPRITE& GetSprite() { return _sprite; }
	};
}