#include "ObjectPool.h"

void ObjectPool::Init(Scene * parent, int count)
{
	_parent = parent;
	Bullet* tempBullet = nullptr;
	for (int i = 0; i < count; i++)
	{
		tempBullet = new Bullet();
		tempBullet->SetActive(false);
		tempBullet->SetName("Bullet");
		_bullets.push_back(tempBullet);
		_parent->AddChild(tempBullet);
	}

	EnemyShip* tempShip = nullptr;
	for (int i = 0; i < count * 0.5f; ++i)
	{
		tempShip = new EnemyShip();
		tempShip->SetName("EnemyShip");
		tempShip->SetSpeed(50.0f);
		tempShip->SetActive(false);
		_enemyShips.push_back(tempShip);
		_parent->AddChild(tempShip);
	}

	UFOShip* ufoShip = nullptr;
	for (int i = 0; i < count * 0.5f; ++i)
	{
		ufoShip = new UFOShip();
		ufoShip->SetSpeed(100.0f);
		ufoShip->SetRotationSpeed(1.f);
		ufoShip->SetActive(false);
		ufoShip->SetName("UFOShip");
		_enemyShips.push_back(ufoShip);
		_parent->AddChild(ufoShip);
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
	tempShip->SetSpeed(50.0f);
	tempShip->SetActive(false);
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
	ufoShip->SetSpeed(100.0f);
	ufoShip->SetActive(false);
	_enemyShips.push_back(ufoShip);
	_parent->AddChild(ufoShip);
	return ufoShip;
}
