#include "UFOShip.h"

UFOShip::UFOShip()
{
	_type = SHIP_TYPE::ENEMY_UFO;
	SetTexture2D(L"Ships/Enemy/enemyUFO.png");
	_screenSize = Director::GetInstance()->GetScreenSize();
	
	SetHP(5);
	SetSpeed(100.f);
	SetRotationSpeed(1.f);
	SetActive(false);
	SetName("UFO");
	SetColor(Color::White());
}

void UFOShip::Update()
{
	SetPerfectCollider();
	CheckScreenOut();
	Move();
}

void UFOShip::Spawn()
{
	float x = rand() % (int)_screenSize.x;
	float y = 0.f;
	SetPosition(x, y);
	SetActive(true);
	SetHP(5);
	SetColor(Color::White());
	_type = SHIP_TYPE::ENEMY_UFO;
}

void UFOShip::Move()
{
	AddPositionY(_speed * Time::deltaTime);
	AddRotation(_rotationSpeed);
}

void UFOShip::CheckScreenOut()
{
	if (_screenSize.y < GetPositionY())
		SetActive(false);
}
