#pragma once

class AutoReleasePool;
namespace AL
{
	class Ref
	{
	public:
		virtual ~Ref();

		virtual void Retain();
		virtual void Release();
		void SetAutoRelease();

		unsigned int GetRefCount() const;

	protected:
		Ref();

		int _refCount;
	};
}