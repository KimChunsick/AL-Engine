#pragma once

#include <Core.h>
#include "Ship.h"

class Bullet : public Sprite 
{
public:
	Bullet();
	virtual ~Bullet();
	
	void Update() override;
	void SetBullet(int damage, float speed, SHIP_TYPE owner);

private:
	void Movement();
	void MoveUp();
	void MoveDown();
	void IsOutOfScreen();

private:
	int _damage = 0;
	float _speed = 0;
	SHIP_TYPE _owner;
	Vector2 _screenSize;
};