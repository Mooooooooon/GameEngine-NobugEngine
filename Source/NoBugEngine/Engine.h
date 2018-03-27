#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SplashScreen.h"
#include <Windows.h>
#include <direct.h>
#include "GameObjectManager.h"
#include "World.h"
#include "Rigidbody.h"
#include "Physics.h"
#include "Input.h"

class Physics;


class NobugEngine
{
public:
	 NobugEngine();
	 void Start();
	 bool Initialize();
	
private:
	//bool IsExiting();
	void InputProcess();
	void Render();
	void GameLoop();
	enum GameState {
		Uninitialized, Initialzed, Paused, ShowingMenu, Playing, Exiting
	};
	GameObjectManager* GM;
	Physics* _physics;
	
	GameState _gameState;

	sf::RenderWindow _mainWindow;
	World* _world;

	InputManager* _inputManager;
	
	SplashScreen _splashScreen;

	friend class SplashScreen;

	static const sf::Time TimePerFrame;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;



};
