#include "SoundManager.h"

namespace AL
{
	void SoundManager::Init()
	{
		SetTimer(DXUTGetHWND(), 0, 10, NULL);
		System_Create(&_soundSystem);
		_soundSystem->init(1, FMOD_INIT_NORMAL, NULL);
	}

	const SoundFile* SoundManager::LoadSound(const std::string fileName)
	{
		for (SoundFile* loadedFile : _loadedList)
		{
			if (loadedFile->fileName == fileName)
				return loadedFile;
		}

		SoundFile* file = new SoundFile();
		file->fileName = fileName;
		std::string path = "../Resources/" + fileName;
		_soundSystem->createSound(path.c_str(), FMOD_DEFAULT, 0, &file->sound);
		_loadedList.push_back(file);
		return file;
	}

	SoundFile * SoundManager::GetSoundFile(const std::string fileName) const
	{
		for (SoundFile* file : _loadedList)
		{
			if (file->fileName == fileName)
				return file;
		}
		return nullptr;
	}

	void SoundManager::SetMode(const std::string fileName, const int mode)
	{
		SoundFile* file = GetSoundFile(fileName);
		file->channel->setMode(mode);
	}

	void SoundManager::Play(const std::string fileName)
	{
		SoundFile* file = GetSoundFile(fileName);
		_soundSystem->playSound(file->sound, NULL, false, &file->channel);
	}

	void SoundManager::Play(const std::string fileName, const float volume)
	{
		SoundFile* file = GetSoundFile(fileName);
		file->channel->setVolume(volume);
		_soundSystem->playSound(file->sound, NULL, false, &file->channel);
	}
}