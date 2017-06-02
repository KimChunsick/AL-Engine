#include "Ship.h"
#include "UIManager.h"

Ship::Ship() : 
	_speed(1.f),
	_damage(0)
{
	
}

void Ship::GetHit(int damage)
{
	_hp -= damage;

	if (_hp <= 0)
	{
		UIManager::GetInstance()->AddScore(static_cast<int>(_type));
		Die();
	}
}

void Ship::Die()
{
	SetActive(false);
}

void Ship::Spawn()
{
	
}
