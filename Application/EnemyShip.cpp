#include "EnemyShip.h"
#include "ObjectPool.h"

EnemyShip::EnemyShip() : 
	_fireDelay(0.f)
{
	_type = SHIP_TYPE::ENEMY_SHIP;
	SetTexture2D(L"Ships/Enemy/enemyShip.png");
	_screenSize = Director::GetInstance()->GetScreenSize();

	SetHP(1);
	SetName("EnemyShip");
	SetSpeed(50.f);
	SetActive(false);
	SetColor(Color::White());
}

void EnemyShip::Update()
{
	SetPerfectCollider();
	CheckScreenOut();
	Move();

	if (CheckTime())
		Fire();
}

void EnemyShip::Fire()
{
	Bullet* temp = ObjectPool::GetInstance()->GetBullet();
	temp->SetPosition(GetPosition());
	temp->SetBullet(_damage, 200.f, SHIP_TYPE::ENEMY_SHIP);
}

void EnemyShip::Spawn()
{
	float x = rand() % (int)_screenSize.x;
	float y = 0.f;
	SetPosition(x, y);
	SetActive(true);
	SetHP(1);
	SetColor(Color::White());
	_type = SHIP_TYPE::ENEMY_SHIP;
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

bool EnemyShip::CheckTime()
{
	_fireDelay += Time::deltaTime;

	if (_fireDelay >= 2.0f && IsActive())
	{
		_fireDelay = 0.f;
		return true;
	}
	return false;
}
