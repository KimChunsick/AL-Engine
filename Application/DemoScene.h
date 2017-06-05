#pragma once

#include <Core.h>
#include "BG.h"
#include "PlayerShip.h"
#include "EnemyShip.h"

class DemoScene : public Scene
{
public:
	DemoScene() = default;
	virtual ~DemoScene() = default;

	void OnEnter() override;
	void OnExit() override;
	void Update() override;

private:
	void CollideBullet();
	void SpawnShip();

private:
	BG* _bg;
	PlayerShip* _player;
	EnemyShip* _enemyShip;
};