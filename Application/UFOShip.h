#pragma once

#include "Ship.h"

class UFOShip : public Ship
{
private:
	Vector2 _screenSize;
	float _rotationSpeed;

public:
	UFOShip();
	virtual ~UFOShip() = default;

	void Update() override;
	void Spawn() override;
	void SetRotationSpeed(float speed) { _rotationSpeed = speed; }
	const float GetRotationSpeed() const { return _rotationSpeed; }

private:
	void Move();
	void CheckScreenOut();
	
};