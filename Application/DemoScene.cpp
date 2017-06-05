#include "DemoScene.h"
#include "ObjectPool.h"
#include "UIManager.h"
#include "DemoScene2.h"

void DemoScene::OnEnter()
{
	Vector2 screenSize = Director::GetInstance()->GetScreenSize();

	_bg = new BG();
	_bg->Init(10, 20);
	_bg->SetName("BG");
	this->AddChild(_bg);

	ObjectPool::GetInstance()->Init(this, 30);
	UIManager::GetInstance()->Init(this);

	Sprite* refCountTest = new Sprite(L"Etc/life.png");
	refCountTest->SetPosition(Director::GetInstance()->GetScreenSize() * 0.5f);
	refCountTest->SetGlobalDepth(100);
	
	_player = new PlayerShip();
	_player->SetHP(3);
	_player->SetSpeed(250.f);
	_player->SetDamage(1);
	_player->SetPositionX(screenSize.x * 0.5f);
	_player->SetPositionY(screenSize.y * 0.8f);
	_player->SetName("Player");
	this->AddChild(_player);
	
	SoundManager::GetInstance()->LoadSound("Burner.mp3");
	SoundManager::GetInstance()->Play("Burner.mp3", 1.f);
	SoundManager::GetInstance()->SetMode("Burner.mp3", FMOD_LOOP_NORMAL);
}

void DemoScene::OnExit()
{
	ObjectPool::GetInstance()->Release();
	UIManager::GetInstance()->Release();
}

void DemoScene::Update()
{
	SpawnShip();
	CollideBullet();

	if (DXUTIsKeyDown('C'))
	{
		Director::GetInstance()->ChangeScene(new DemoScene2());
	}
}

void DemoScene::CollideBullet()
{
	for (auto bullet : ObjectPool::GetInstance()->GetBulletList())
	{
		bullet->CollideBullet(_player);
		for (auto ship : ObjectPool::GetInstance()->GetEnemyShipList())
		{
			bullet->CollideBullet(ship);
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
			ship = ObjectPool::GetInstance()->GetEnemyShip();
		else
			ship = ObjectPool::GetInstance()->GetUFOShip();
		
		timer = 0.f;
		ship->Spawn();
		flag = !flag;
	}
}
