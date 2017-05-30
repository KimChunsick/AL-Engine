#include "Core.h"
#include "Director.h"

namespace AL
{
	LPD3DXSPRITE Director::_sprite;

	Director::Director() :
		_currentScene(nullptr),
		_nextScene(nullptr)
	{
		
	}

	void Director::Init()
	{
		D3DXCreateSprite(DXUTGetD3D9Device(), &_sprite);
	}

	void Director::Update()
	{
		UpdateGame();
		AutoReleasePool::GetInstance()->AutoRelease();
	}

	void Director::ReplaceScene(Scene* const scene)
	{
		if (scene == _nextScene)
			return;
		
		if (_nextScene)
		{
			if (_nextScene->IsActive())
			{
				_nextScene->OnExit();
			}
			_nextScene = nullptr;
		}
		_nextScene = scene;
	}

	const Vector2 Director::GetScreenSize() const
	{
		RECT rect;
		GetClientRect(DXUTGetHWND(), &rect);
		return Vector2(rect.right - rect.left, rect.bottom - rect.top);
	}

	void Director::UpdateGame()
	{
		if (_nextScene)
			SetNextScene();
		
		_currentScene->Visit();
		Renderer::GetInstance()->Render();
	}

	void Director::SetNextScene()
	{
		if (_currentScene)
		{
			_currentScene->Release();
		}
		_currentScene = _nextScene;
		_currentScene->OnEnter();
		_nextScene->Retain();
		_nextScene = nullptr;
	}
}