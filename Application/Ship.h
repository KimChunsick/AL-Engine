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
	virtual ~Ship() = default;

	void SetSpeed(float speed) { _speed = speed; }
	float GetSpeed() { return _speed; }

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

	void SetHP(int hp) { _hp = hp; }
	int GetHP() { return _hp; }

	void GetHit(int damage);
	virtual void Spawn();

	void SetType(SHIP_TYPE type) { _type = type; }
	SHIP_TYPE GetType() { return _type; }

	void Sibal(Node* parent)
	{
		for (int i = 0; i < 4; i++)
		{
			sibal[i] = new Sprite(L"Debug.png");
			parent->AddChild(sibal[i]);
		}
	}

protected:
	virtual void Die();

protected:
	int _damage;
	int _hp;
	float _speed;
	SHIP_TYPE _type;
	Sprite* sibal[4];
};