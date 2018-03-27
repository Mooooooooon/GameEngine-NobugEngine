#pragma once

#include "BaseComponent.h"
#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"


class Audio : public BaseComponent {
public:
	Audio(std::string path);

	sf::SoundBuffer Soundbuffer;
	sf::Sound Sound;
	sf::Music Music;


	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	

	void PlaySound();

};