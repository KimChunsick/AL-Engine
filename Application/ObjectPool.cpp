#include "ObjectPool.h"

void ObjectPool::Init(Scene * parent, int count)
{
	_parent = parent;
	Bullet* tempBullet = nullptr;
	for (int i = 0; i < count; i++)
	{
		tempBullet = new Bullet();
		_bullets.push_back(tempBullet);
		_parent->AddChild(tempBullet);
	}

	Ship* _enemyShip = nullptr;;
	for (int i = 0; i < count * 0.5f; ++i)
	{
		_enemyShip = new EnemyShip();
		_enemyShips.push_back(_enemyShip);
		_parent->AddChild(_enemyShip);
	}

	for (int i = 0; i < count * 0.5f; ++i)
	{
		_enemyShip = new UFOShip();
		_enemyShips.push_back(_enemyShip);
		_parent->AddChild(_enemyShip);
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

Ship * ObjectPool::GetEnemyShip()
{
	for (Ship* ship : _enemyShips)
	{
		if (!ship->IsActive() && ship->GetType() == SHIP_TYPE::ENEMY_SHIP)
			return ship;
	}

	EnemyShip* tempShip = new EnemyShip();
	tempShip = new EnemyShip();
	_enemyShips.push_back(tempShip);
	_parent->AddChild(tempShip);
	return tempShip;
}

Ship * ObjectPool::GetUFOShip()
{
	for (Ship* ship : _enemyShips)
	{
		if (!ship->IsActive() && ship->GetType() == SHIP_TYPE::ENEMY_UFO)
			return ship;
	}

	UFOShip* ufoShip = new UFOShip();
	_enemyShips.push_back(ufoShip);
	_parent->AddChild(ufoShip);
	return ufoShip;
}
