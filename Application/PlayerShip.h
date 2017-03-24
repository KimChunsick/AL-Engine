#pragma once

#include <Core.h>
#include "Ship.h"

class PlayerShip : public Ship
{
public:
	PlayerShip();
	virtual ~PlayerShip() {}
	void Update() override;

private:
	void GetKey();
	void Fire();
};