#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SplashScreen.h"
#include <Windows.h>
#include <direct.h>
#include "GameObjectManager.h"



class NobugEngine
{
public:
	 void Start();
	 bool Initialize();
	
private:
	//bool IsExiting();
	void InputProcess();
	void GameLoop();
	enum GameState {
		Uninitialized, Initialzed, Paused, ShowingMenu, Playing, Exiting
	};
	GameObjectManager GM;
	
	 GameState _gameState;
	 sf::RenderWindow _mainWindow;
	
	SplashScreen _splashScreen;

	friend class SplashScreen;

	static const sf::Time TimePerFrame;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;



};
