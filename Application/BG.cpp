#include "BG.h"

BG::BG() :
	_bg(nullptr),
	_screenSize(Vector2::Zero())
{ }

void BG::Init(int meteorCount, int starCount)
{
	_screenSize = Director::GetInstance()->GetScreenSize();

	_bg = new Sprite(L"BG/backgroundColor.png");
	_bg->SetPosition(Director::GetInstance()->GetScreenSize() * 0.5f);
	_bg->SetScale(Vector2(9, 5));
	_bg->SetName("BG");
	this->AddChild(_bg);

	Star* star = nullptr;
	for (int i = 0; i < starCount; i++)
	{
		if (i % 2 == 0)
			star = new Star(STAR_TYPE::BIG);
		else
			star = new Star(STAR_TYPE::SMALL);
		star->SetPositionX((rand() % (int)_screenSize.x));
		star->SetPositionY((rand() % (int)_screenSize.y));
		star->SetSpeed(100);
		star->SetName("Star");
		this->AddChild(star);
		_stars.push_back(star);
	}
}

void BG::Update()
{
}

void BG::MeteorsControl()
{
}

void BG::StarsControl()
{
}
