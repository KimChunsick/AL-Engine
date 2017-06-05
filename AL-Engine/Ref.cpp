#include "Core.h"
#include "Ref.h"

namespace AL
{
	Ref::Ref() :
		_refCount(1)
	{

	}

	Ref::~Ref()
	{

	}

	void Ref::Retain()
	{
		++_refCount;
	}

	void Ref::Release()
	{
		--_refCount;

		if (_refCount == 0)
			delete this;
	}

	void Ref::ForceRelease()
	{
		_refCount = 0;
		delete this;
	}

	void Ref::SetAutoRelease()
	{
		AutoReleasePool::GetInstance()->AddPool(this);
	}

	const unsigned int Ref::GetRefCount() const
	{
		return _refCount;
	}
}