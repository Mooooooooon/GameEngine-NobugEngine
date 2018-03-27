#include "Audio.h"

Audio::Audio(std::string path)
{
	Music.openFromFile(path);
}

void Audio::Awake()
{
}

void Audio::Start()
{
}

void Audio::Update()
{
}

void Audio::LateUpdate()
{
}

void Audio::PlaySound()
{
	if (Sound.getBuffer())
		Sound.play();
	else {
		Music.play();
	}
}
