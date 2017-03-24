#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	_type = SHIP_TYPE::ENEMY_SHIP;
	SetTexture2D(L"Ships/Enemy/enemyShip.png");
	_screenSize = Director::GetInstance()->GetScreenSize();
}

EnemyShip::~EnemyShip()
{
}

void EnemyShip::Update()
{
	Move();
}

void EnemyShip::Spawn()
{
	float x = rand() % (int)_screenSize.x;
	float y = 0.f;
	SetPosition(x, y);
	SetActive(true);
}

void EnemyShip::Move()
{
	AddPositionY(_speed * Time::deltaTime);
}

void EnemyShip::CheckScreenOut()
{
	if (_screenSize.y < GetPositionY())
		SetActive(false);
}
