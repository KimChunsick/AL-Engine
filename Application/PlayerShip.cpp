#include "PlayerShip.h"
#include "ObjectPool.h"
#include "Bullet.h"

PlayerShip::PlayerShip()
{
	SetTexture2D(L"Ships/Player/player.png");
	_type = SHIP_TYPE::PLAYER_SHIP;
}

void PlayerShip::Update()
{
	SetPerfectCollider();
	GetKey();
}

void PlayerShip::GetKey()
{
	static float timer = 0.f;
	timer += Time::deltaTime;
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		SetTexture2D(L"Ships/Player/playerRight.png");
		AddPositionX(_speed * Time::deltaTime);
	}
	else if (DXUTIsKeyDown(VK_LEFT))
	{
		SetTexture2D(L"Ships/Player/playerLeft.png");
		AddPositionX(-_speed * Time::deltaTime);
	}
	else
	{
		SetTexture2D(L"Ships/Player/player.png");
	}

	if (DXUTIsKeyDown(VK_UP))
	{
		AddPositionY(-_speed * Time::deltaTime);
	}

	if (DXUTIsKeyDown(VK_DOWN))
	{
		AddPositionY(_speed * Time::deltaTime);
	}

	if (DXUTIsKeyDown(VK_SPACE) && timer >= 0.1f)
	{
		Fire();
		timer = 0.f;
	}
}

void PlayerShip::Fire()
{
	Bullet* temp = ObjectPool::GetInstance()->GetBullet();
	temp->SetBullet(_damage, 300.f, SHIP_TYPE::PLAYER_SHIP);
	temp->SetPosition(GetPosition());
}
