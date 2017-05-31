#pragma once

#include <Core.h>
#include "Ship.h"

class Bullet : public Sprite 
{
public:
	Bullet();
	virtual ~Bullet() = default;
	
	void Update() override;
	void SetBullet(int damage, float speed, SHIP_TYPE owner);
	void CollideBullet(Ship* ship);

private:
	void Movement();
	void MoveUp();
	void MoveDown();
	void IsOutOfScreen();
	void HitCheck();

private:
	int _damage = 0;
	float _hitDelay = 0.f;
	float _speed = 0;
	bool _isHit = false;
	SHIP_TYPE _owner;
	Vector2 _screenSize;
};