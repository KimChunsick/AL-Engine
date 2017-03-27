#include "DemoScene.h"
#include "ObjectPool.h"

void DemoScene::OnEnter()
{
	Vector2 screenSize = Director::GetInstance()->GetScreenSize();

	TextureManager::GetInstance()->LoadTexture(L"Laser/laserGreen.png");
	TextureManager::GetInstance()->LoadTexture(L"Laser/laserGreenShot.png");
	TextureManager::GetInstance()->LoadTexture(L"Laser/laserRed.png");
	TextureManager::GetInstance()->LoadTexture(L"Laser/laserRedShot.png");

	_bg = new BG();
	_bg->Init(10, 20);
	this->AddChild(_bg);

	ObjectPool::GetInstance()->Init(this, 20);

	Sprite* refCountTest = new Sprite(L"Etc/life.png");
	refCountTest->SetPosition(Director::GetInstance()->GetScreenSize() * 0.5f);
	refCountTest->SetGlobalDepth(100);

	_player = new PlayerShip();
	_player->SetSpeed(250.f);
	_player->SetPositionX(screenSize.x * 0.5f);
	_player->SetPositionY(screenSize.y * 0.8f);
	this->AddChild(_player);

	_enemyShip = new EnemyShip();
	_enemyShip->SetSpeed(50.0f);
	_enemyShip->SetPositionX(screenSize.x * 0.5f);
	_enemyShip->SetPositionY(screenSize.y * 0.2f);
	this->AddChild(_enemyShip);
}

void DemoScene::OnExit()
{
	
}

void DemoScene::Update()
{
	for (auto bullet : ObjectPool::GetInstance()->GetBulletList())
	{
		/*
		if (!bullet->IsActive())
			continue;
		*/
		
		bullet->CollideBullet(_enemyShip);

		/*if (_enemyShip->GetCollider().IsAABB(bullet->GetCollider()))
		{
			bullet->SetActive(false);
		}*/

		/*for (auto ship : ObjectPool::GetInstance()->GetEnemyShipList())
		{
			if (bullet->GetCollider().IsAABB(ship->GetCollider()))
			{
				bullet->SetActive(false);
			}
		}*/
	}
}
