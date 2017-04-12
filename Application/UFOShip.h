#pragma once

#include "Ship.h"

class UFOShip : public Ship
{
public:
	UFOShip();
	virtual ~UFOShip();

	void Update() override;
	void Spawn() override;

private:
	void Move();
	void CheckScreenOut();

private:
	Vector2 _screenSize;
};