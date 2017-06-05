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
		virtual void ForceRelease();
		void SetAutoRelease();

		const unsigned int GetRefCount() const;

	protected:
		Ref();

		int _refCount;
	};
}