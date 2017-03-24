#pragma once

#include <Core.h>
#include <vector>
#include "Star.h"

class BG : public Sprite
{
public:
	BG();
	virtual ~BG() {}

	void Init(int meteorCount, int starCount);
	void Update() override;


private:
	void MeteorsControl();
	void StarsControl();

private:
	Vector2 _screenSize;
	Sprite* _bg;
	std::vector<Star*> _stars;
};