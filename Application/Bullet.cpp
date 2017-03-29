#include "Bullet.h"

Bullet::Bullet()
{
	_screenSize = Director::GetInstance()->GetScreenSize();
}

Bullet::~Bullet()
{
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

	SetActive(true);
}

void Bullet::CollideBullet(Ship * ship)
{
	if (!GetCollider().IsAABB(ship->GetCollider()))
		return;

	cout << "??" << endl;

	if (ship->GetType() == SHIP_TYPE::PLAYER_SHIP && this->_owner != SHIP_TYPE::PLAYER_SHIP)
	{
		ship->SetDamage(this->_damage);
		SetTexture2D(L"Laser/laserGreenShot.png");
		_isHit = true;
	}
	else if (ship->GetType() != SHIP_TYPE::PLAYER_SHIP && this->_owner == SHIP_TYPE::PLAYER_SHIP)
	{
		ship->SetDamage(this->_damage);
		SetTexture2D(L"Laser/laserRedShot.png");
		_isHit = true;
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
		//printf("%f\n", _hitDelay) ;
		if (_hitDelay >= 0.3f)
		{
			_isHit = false;
			_hitDelay = 0.f;
			SetActive(false);
		}
	}
}
