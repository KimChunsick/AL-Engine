#include "Core.h"
#include "AutoReleasePool.h"

namespace AL
{
	AutoReleasePool::AutoReleasePool()
	{
		_poolObjects.reserve(100);
	}

	AutoReleasePool::~AutoReleasePool()
	{ }

	void AutoReleasePool::AddPool(Ref * ref)
	{
		_poolObjects.push_back(ref);
	}

	void AutoReleasePool::AutoRelease()
	{
		for (const auto &ref : _poolObjects)
		{
			ref->Release();
		}
		_poolObjects.clear();
	}
}
