#include "Engine.h"
#include "Initialize.h"




void NobugEngine::Start() {
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "NobugGame");
	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();

}

void NobugEngine::Initialize()
{
	//Check is only instance;
	if (!Initialize::CheckIsOnlyInstance("NobugGame")) {
		cout << "Check instance : One instance has already running." << endl;
		return;
	}

	//Initialize graphic system & show splash screen
	Initialize::InitGraphicSystem(&_mainWindow, 700, 500, "NobugGame");
	_splashScreen.Show(_mainWindow);

	//Check system
	if (!Initialize::CheckHardDriveSpace(300 * 1024 * 1024)) {
		cout << "CheckStorage failure : Not enough physical storage." << endl;
		return;
	}

	if (!Initialize::CheckRAM(500)) {
		cout << "Check RAM failure, Not enough RAM" << endl;
		return;
	}

	if (!Initialize::CheckInputDevice()) {
		cout << "Check input device failure, No input device" << endl;
		return;
	}

	if (!Initialize::CheckOutputDevice()) {
		cout << "Check output device failure, No output device" << endl;
		return;
	}

	if (!Initialize::CheckCPUSpeed(2000)) {
		cout << "Check CPU speed failure, CPU speed too low" << endl;
		return;
	}

	//Initialize audio system
	Initialize::InitAudioSystem();

	//Initalize other...
	//Implement here

	//Initialization success
	_gameState = ShowingSplash;

	
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
