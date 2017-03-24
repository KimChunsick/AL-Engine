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

private:
	Scene* _parent;
	std::list<Bullet*> _bullets;
};