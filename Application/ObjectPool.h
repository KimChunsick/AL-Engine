#pragma once

#include <Core.h>
#include <list>
#include "Bullet.h"
#include "Ship.h"

class ObjectPool : public Singleton<ObjectPool>
{
public:
	void Init(Scene* parent, int count);
	
	Bullet* GetBullet();
	Ship* GetShip();

	std::list<Bullet*> GetBulletList() { return _bullets; }
	std::list<Ship*> GetEnemyShipList() { return _enemyShips; }

private:
	Scene* _parent;
	std::list<Bullet*> _bullets;
	std::list<Ship*> _enemyShips;
};