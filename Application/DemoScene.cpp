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
	_bg->SetName("BG");
	this->AddChild(_bg);

	ObjectPool::GetInstance()->Init(this, 20);

	Sprite* refCountTest = new Sprite(L"Etc/life.png");
	refCountTest->SetPosition(Director::GetInstance()->GetScreenSize() * 0.5f);
	refCountTest->SetGlobalDepth(100);
	
	_player = new PlayerShip();
	_player->SetSpeed(250.f);
	_player->SetDamage(1);
	_player->SetPositionX(screenSize.x * 0.5f);
	_player->SetPositionY(screenSize.y * 0.8f);
	_player->SetName("Player");
	this->AddChild(_player);
	
	Label* _label = new Label();
	_label->Init(L"Å×½ºÆ®", 20, 50, LABEL_TYPE::NORMAL, true, LABEL_QUALITY::NORMAL);
	_label->SetPosition(Director::GetInstance()->GetScreenSize() * 0.5f);
	_label->SetFormat(LABEL_ALIGHN::RIGHR);
	_label->SetGlobalDepth(10000);
	this->AddChild(_label);
	
	SoundManager::GetInstance()->LoadSound("Burner.mp3");
	SoundManager::GetInstance()->SetMode("Burner.mp3", FMOD_LOOP_NORMAL);
	SoundManager::GetInstance()->Play("Burner.mp3", 1.f);
}

void DemoScene::OnExit()
{

}

void DemoScene::Update()
{
	SpawnShip();
	CollideBullet();
}

void DemoScene::CollideBullet()
{
	for (auto bullet : ObjectPool::GetInstance()->GetBulletList())
	{
		if (!bullet->IsActive())
			continue;

		bullet->CollideBullet(_player);
		for (auto enemyShip : ObjectPool::GetInstance()->GetEnemyShipList())
		{
			bullet->CollideBullet(enemyShip);
		}
	}
}

void DemoScene::SpawnShip()
{
	static float timer = 0.f;
	static bool flag = false;
	timer += Time::deltaTime;

	if (timer >= 1.5f)
	{
		Ship* ship = nullptr;
		if (flag)
			ship = ObjectPool::GetInstance()->GetUFOShip();
		else
			ship = ObjectPool::GetInstance()->GetEnemyShip();
		timer = 0.f;
		ship->Spawn();
		flag = !flag;
	}
}
