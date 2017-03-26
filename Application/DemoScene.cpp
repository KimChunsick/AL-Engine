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

	EnemyShip* enemyShip = new EnemyShip();
	enemyShip->SetSpeed(50.0f);
	enemyShip->SetPositionX(screenSize.x * 0.5f);
	enemyShip->SetPositionY(screenSize.y * 0.2f);
	this->AddChild(enemyShip);
}

void DemoScene::OnExit()
{
	
}

void DemoScene::Update()
{
	
}
