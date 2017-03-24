#pragma once

#include "Types.h"
#include <vector>

namespace AL
{
	class Ref;
	class AutoReleasePool : public Singleton<AutoReleasePool>
	{
	public:
		AutoReleasePool();
		~AutoReleasePool();

		void AddPool(Ref* ref);
		void AutoRelease();
		

	private:
		std::vector<Ref*> _poolObjects;
		bool _clearPool;
	};
}