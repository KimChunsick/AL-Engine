#include "SoundManager.h"

void AL::SoundManager::Init()
{
	SetTimer(DXUTGetHWND(), 0, 10, NULL);
	System_Create(&_soundSystem);
	_soundSystem->init(1, FMOD_INIT_NORMAL, 0);

}
