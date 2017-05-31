#pragma once

#include "Types.h"
#include <fmod.hpp>
#include <iostream>
#include <list>

using namespace FMOD;

namespace AL
{
	class SoundFile
	{
	public:
		SoundFile() = default;
		~SoundFile() = default;
		
		Sound* sound;
		std::string fileName;
		Channel* channel;
	};

	class SoundManager : public Singleton<SoundManager>
	{
	private:
		System* _soundSystem;
		std::list<SoundFile*> _loadedList;

	public:
		SoundManager() = default;
		virtual ~SoundManager() = default;

		void Init();
		const SoundFile* LoadSound(const std::string fileName);
		SoundFile* GetSoundFile(const std::string fileName) const;

		void SetMode(const std::string fileName, const int mode);
		void Play(const std::string fileName);
		void Play(const std::string fileName, const float volume);
	};
}