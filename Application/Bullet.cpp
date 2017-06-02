#include "Bullet.h"

Bullet::Bullet() : 
	_owner(SHIP_TYPE::PLAYER_SHIP), 
	_isHit(false), 
	_hitDelay(0.f)
{
	_screenSize = Director::GetInstance()->GetScreenSize();
	SetActive(false);
	SetName("Bullet");
}

void Bullet::Update()
{
	SetPerfectCollider();
	Movement();
	IsOutOfScreen();
	HitCheck();
}

void Bullet::SetBullet(int damage, float speed, SHIP_TYPE owner)
{
	_damage = damage;
	_speed = speed;
	_owner = owner;

	if (_owner == SHIP_TYPE::PLAYER_SHIP)
		SetTexture2D(L"Laser/laserRed.png");
	else
		SetTexture2D(L"Laser/laserGreen.png");

	SetPerfectCollider();
	SetActive(true);
	_isHit = false;
	_hitDelay = 0.f;
}

void Bullet::CollideBullet(Ship * ship)
{
	if (!ship->IsActive() || !IsActive())
		return;

	if (_isHit)
		return;

	if (!GetCollider().IsAABB(ship->GetCollider()))
		return;

	switch (ship->GetType())
	{
	case SHIP_TYPE::ENEMY_SHIP:
		if (_owner == SHIP_TYPE::PLAYER_SHIP)
		{
			SetTexture2D(L"Laser/laserRedShot.png");
			ship->GetHit(_damage);
			_isHit = true;
		}
		break;

	case SHIP_TYPE::ENEMY_UFO:
		if (_owner == SHIP_TYPE::PLAYER_SHIP)
		{
			SetTexture2D(L"Laser/laserRedShot.png");
			ship->GetHit(_damage);
			_isHit = true;
		}
		break;

	case SHIP_TYPE::PLAYER_SHIP:
		if (_owner != SHIP_TYPE::PLAYER_SHIP)
		{
			SetTexture2D(L"Laser/laserGreenShot.png");
			ship->GetHit(_damage);
			_isHit = true;
		}
		break;

	default:
		printf("Unknown Type! %d\n", ship->GetType());
		break;
	}
}

void Bullet::Movement()
{
	if (_owner == SHIP_TYPE::PLAYER_SHIP)
		MoveUp();
	else
		MoveDown();
}

void Bullet::MoveUp()
{
	AddPositionY(-_speed * Time::deltaTime);
}

void Bullet::MoveDown()
{
	AddPositionY(_speed * Time::deltaTime);
}

void Bullet::IsOutOfScreen()
{
	if (_screenSize.y < GetPositionY() || 0 > GetPositionY() || _screenSize.x < GetPositionX() || 0 > GetPositionX())
		SetActive(false);
}

void Bullet::HitCheck()
{
	if (_isHit)
	{
		_hitDelay += Time::deltaTime;
		_speed = 0.f;
		if (_hitDelay >= 0.3f)
			SetActive(false);
	}
}
