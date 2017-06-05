#pragma once

#include <Core.h>

class DemoScene2 : public Scene
{
public:
	DemoScene2() = default;
	virtual ~DemoScene2() = default;

	void OnEnter() override;
	void OnExit() override;
	void Update() override;
};