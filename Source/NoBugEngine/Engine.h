#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SplashScreen.h"
#include <Windows.h>
#include <direct.h>



class NobugEngine
{
public:
	 void Start();
	 void Initialize();
	
private:
	//bool IsExiting();
	void GameLoop();
	enum GameState {
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	 GameState _gameState;
	 sf::RenderWindow _mainWindow;
	
	SplashScreen _splashScreen;

	friend class SplashScreen;


};
