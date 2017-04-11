#include "ObjectPool.h"

void ObjectPool::Init(Scene * parent, int count)
{
	_parent = parent;
	Bullet* tempBullet = nullptr;
	for (int i = 0; i < count; i++)
	{
		tempBullet = new Bullet();
		tempBullet->SetActive(false);
		_bullets.push_back(tempBullet);
		_parent->AddChild(tempBullet);
	}

	EnemyShip* tempShip = nullptr;
	for (int i = 0; i < count * 0.5f; ++i)
	{
		tempShip = new EnemyShip();
		tempShip->SetSpeed(50.0f);
		tempShip->SetActive(false);
		_enemyShips.push_back(tempShip);
		_parent->AddChild(tempShip);
	}
}

Bullet * ObjectPool::GetBullet()
{
	for (Bullet* bullet : _bullets)
	{
		if (!bullet->IsActive())
			return bullet;
	}
	Bullet* tempBullet = new Bullet();
	tempBullet->SetActive(false);
	_parent->AddChild(tempBullet);
	_bullets.push_back(tempBullet);
	return tempBullet;
}

Ship * ObjectPool::GetShip()
{
	for (Ship* ship : _enemyShips)
	{
		if (!ship->IsActive())
			return ship;
	}
	Ship* tempShip = new Ship();
	tempShip->SetActive(false);
	_parent->AddChild(tempShip);
	_enemyShips.push_back(tempShip);
	return tempShip;
}
