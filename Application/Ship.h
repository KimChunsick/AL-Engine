#pragma once

#include <Core.h>

enum class SHIP_TYPE : short
{
	PLAYER_SHIP,
	ENEMY_SHIP,
	ENEMY_UFO,
};

class Ship : public Sprite
{
public:
	Ship();
	virtual ~Ship();

	void SetSpeed(float speed) { _speed = speed; }
	float GetSpeed() { return _speed; }

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

	void SetHP(int hp) { _hp = hp; }
	int GetHP() { return _hp; }

	void GetHit(int damage);

	void SetType(SHIP_TYPE type) { _type = type; }
	SHIP_TYPE GetType() { return _type; }

protected:
	virtual void Die();
	virtual void Spawn();

protected:
	int _damage;
	int _hp;
	float _speed;
	SHIP_TYPE _type;

};