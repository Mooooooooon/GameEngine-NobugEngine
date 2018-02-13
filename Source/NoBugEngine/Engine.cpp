#include "Engine.h"


void NobugEngine::Start() {
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "NobugGame");
	_gameState = ShowingSplash;
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
	sf::Event event;
	while (_gameState == ShowingSplash)
	{

		_splashScreen.Show(_mainWindow);
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed) {
				_gameState = Exiting;
			}
		}
	}

	_mainWindow.clear();
}
