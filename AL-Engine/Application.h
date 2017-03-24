#pragma once

#include "DXUT\Core\DXUT.h"
#include <string>

namespace AL
{
	class Scene;

	class Application
	{
	public:
		Application();
		~Application();

		void Init(Scene* scene);
		int Start();

	public:
		int width;
		int height;
		bool isWindow;
		std::wstring title;

	};
}