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
	}
	else if (ship->GetType() != SHIP_TYPE::PLAYER_SHIP && this->_owner == SHIP_TYPE::PLAYER_SHIP)
	{
		ship->SetDamage(this->_damage);
		this->SetActive(false);
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
