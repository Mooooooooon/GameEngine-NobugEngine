#include "Engine.h"


void NobugEngine::Start() {
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "NobugGame");
	
	/*
	_gameState = NobugEngine::ShowingSplash;
	SplashScreen splash;
	splash.Show(_mainWindow);




	*/

	sf::Event ev;
	while (_gameState == ShowingSplash)
	{
		
	}
	_gameState = NobugEngine::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();

}

void NobugEngine::Initialize()
{
	
}

bool NobugEngine::IsExiting()
{
	return false;
}

void NobugEngine::GameLoop()
{
}
