#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class NobugEngine
{
public:
	static void Start();
	static void Initialize();
	enum GameState {
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
private:
	static bool IsExiting();
	static void GameLoop();

	

	

};
