#include "ObjectPool.h"

void ObjectPool::Init(Scene* parent, int count)
{
	_parent = parent;

	Bullet* tempBullet = nullptr;
	for (int i = 0; i < count; i++)
	{
		tempBullet = new Bullet();
		_parent->AddChild(tempBullet);
		tempBullet->SetActive(false);
		_bullets.push_back(tempBullet);
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
	_parent->AddChild(tempBullet);
	tempBullet->SetActive(false);
	_bullets.push_back(tempBullet);
	return tempBullet;
}

Ship * ObjectPool::GetShip()
{
	return nullptr;
}
