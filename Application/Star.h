#pragma once

#include <Core.h>

enum class STAR_TYPE
{
	BIG,
	SMALL,
};

class Star : public Sprite
{
public:
	Star();
	Star(STAR_TYPE type);
	virtual ~Star() {}

	void Update() override;
	void SetSpeed(float speed) { _speed = speed + (rand() % 10); }

private:
	void PositionControl();
	void LerpingScale();

private:
	Vector2 _screenSize;
	Vector2 _targetScale;
	float _speed;
	float _time;
	float _randomValue;
	bool _isScaleUp;
};