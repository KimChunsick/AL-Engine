#pragma once

#include <Core.h>
#include <list>
#include "Bullet.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "UFOShip.h"

class ObjectPool : public Singleton<ObjectPool>
{
public:
	void Init(Scene* parent, int count);
	void Release();
	Bullet* GetBullet();
	Ship* GetEnemyShip();
	Ship* GetUFOShip();

	std::list<Bullet*> GetBulletList() { return _bullets; }
	std::list<Ship*> GetEnemyShipList() { return _enemyShips; }

private:
	Scene* _parent;
	std::list<Bullet*> _bullets;
	std::list<Ship*> _enemyShips;
};