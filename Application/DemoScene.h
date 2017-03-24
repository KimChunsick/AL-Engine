#pragma once

#include <Core.h>
#include "BG.h"
#include "PlayerShip.h"
#include "EnemyShip.h"

class DemoScene : public Scene
{
public:
	void OnEnter() override;
	void OnExit() override;
	void Update() override;

private:
	BG* _bg;
	PlayerShip* _player;
};