#include "Ship.h"

Ship::Ship() : 
	_speed(1.f),
	_damage(0)
{ }

Ship::~Ship()
{ }

void Ship::GetHit(int damage)
{
	_hp -= damage;

	if (_hp <= 0)
	{
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