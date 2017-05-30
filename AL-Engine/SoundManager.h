#pragma once

#include "Types.h"
#include <list>
#include <fmod.hpp>

using namespace FMOD;

namespace AL
{
	class SoundManager : public Singleton<SoundManager>
	{
	private:
		System* _soundSystem;
		std::list<Sound*> _loadedList;
		Channel* _channel;

	public:
		SoundManager() = default;
		virtual ~SoundManager() = default;

		void Init();
	};
}