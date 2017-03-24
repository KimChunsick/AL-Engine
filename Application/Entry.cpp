#include <Core.h>
#include <time.h>
#include "DemoScene.h"

int _tmain(int argv, _TCHAR argc[])
{
	srand(time(NULL));
	Application app;
	app.isWindow = true;
	app.width = 1280;
	app.height = 720;
	app.Init(new DemoScene());
	return app.Start();
}