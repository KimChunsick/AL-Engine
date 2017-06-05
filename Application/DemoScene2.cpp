#include "DemoScene2.h"
#include "DemoScene.h"

void DemoScene2::OnEnter()
{
}

void DemoScene2::OnExit()
{
}

void DemoScene2::Update()
{
	if (DXUTIsKeyDown('V'))
	{
		Director::GetInstance()->ChangeScene(new DemoScene());
	}
}
