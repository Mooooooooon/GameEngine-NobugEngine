#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "SplashScreen.h"


class NobugEngine
{
public:
	static void Start();
	static void Initialize();
	
private:
	static bool IsExiting();
	static void GameLoop();
	enum GameState {
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
	friend class SplashScreen;


};
