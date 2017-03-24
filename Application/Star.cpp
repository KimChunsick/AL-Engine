#include "Star.h"

Star::Star() 
	: _speed(1.f), 
	_screenSize(Vector2::Zero()), 
	_isScaleUp(true),
	_targetScale(Vector2(2.f, 2.f)),
	_time(0.f)
{ }

Star::Star(STAR_TYPE type) : 
	_speed(1.f), 
	_screenSize(Vector2::Zero()), 
	_isScaleUp(true),
	_targetScale(Vector2(2.f, 2.f)),
	_time(0.f)
{
	if (type == STAR_TYPE::BIG)
		SetTexture2D(L"BG/starBig.png");
	else
		SetTexture2D(L"BG/starSmall.png");
	_screenSize = Director::GetInstance()->GetScreenSize();
	_randomValue = (rand() % 3) + 1;
}

void Star::Update()
{
	PositionControl();
	LerpingScale();
}

void Star::PositionControl()
{
	if (GetPositionY() > _screenSize.y)
	{
		static int _flag = 1;

		SetPositionX((rand() % (int)_screenSize.x));
		SetPositionY(0.f);
		_randomValue = (rand() % 2) + 0.5f;
		if (_speed <= 300)
		{
			_speed = _speed + ((rand() % 10) * _flag);
			_flag *= -1;
		}
	}
	AddPositionY(_speed * Time::deltaTime);
}

void Star::LerpingScale()
{
	_time += Time::smoothDeltaTime * _randomValue * Time::timeScale;
	if (_isScaleUp)
	{
		if (GetScale() == _targetScale)
		{
			_targetScale = Vector2(1.f, 1.f);
			_isScaleUp = false;
			_time = 0.f;
		}
	}
	else
	{
		if (GetScale() == _targetScale)
		{
			_targetScale = Vector2(1.5f, 1.5f);
			_isScaleUp = true;
			_time = 0.f;
		}
	}
	
	SetScale(Vector2::Lerping(GetScale(), _targetScale, _time));
}
