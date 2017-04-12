#pragma once

#include <Core.h>
#include "Ship.h"

class EnemyShip : public Ship
{
public:
	EnemyShip();
	virtual ~EnemyShip();

	void Update() override;
	void Spawn() override;
	void Fire();

private:
	void Move();
	void CheckScreenOut();
	bool CheckTime();

private:
	Vector2 _screenSize;
	float _fireDelay;
};