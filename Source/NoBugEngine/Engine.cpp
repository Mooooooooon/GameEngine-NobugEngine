#include "Engine.h"
#include "Initialize.h"


const sf::Time NobugEngine::TimePerFrame = sf::milliseconds(17); // 16.6666 = 60fps

NobugEngine::NobugEngine() :
	_mainWindow(),
	_gameState(Uninitialized)
{

}

void NobugEngine::Start() {
	if (_gameState == Uninitialized)
		return;


	_mainWindow.create(sf::VideoMode(1024, 768, 32), "NobugGame");
	


	while (_gameState != Exiting)
	{
		GameLoop();
	}

	_mainWindow.close();

}

bool NobugEngine::Initialize()
{
	//Check is only instance;
	if (!Initialize::CheckIsOnlyInstance("NobugGame")) {
		cout << "Check instance : One instance has already running." << endl;
		return false;
	}

	//Initialize graphic system & show splash screen
	Initialize::InitGraphicSystem(&_mainWindow, 1024, 768, "NobugGame");
	_splashScreen.Show(_mainWindow);

	//Check system
	if (!Initialize::CheckHardDriveSpace(300 * 1024 * 1024)) {
		cout << "CheckStorage failure : Not enough physical storage." << endl;
		return false;
	}

	if (!Initialize::CheckRAM(500)) {
		cout << "Check RAM failure, Not enough RAM" << endl;
		return false;
	}

	if (!Initialize::CheckInputDevice()) {
		cout << "Check input device failure, No input device" << endl;
		return false;
	}

	if (!Initialize::CheckOutputDevice()) {
		cout << "Check output device failure, No output device" << endl;
		return false;
	}

	if (!Initialize::CheckCPUSpeed(2000)) {
		cout << "Check CPU speed failure, CPU speed too low" << endl;
		return false;
	}
	_physics = new Physics();

	
	GM = new GameObjectManager();
	
	Initialize::InitAudioSystem();

	_world = new World(_physics,GM);
	_world->Start();

	_gameState = Initialzed;

	return true;
}
//
//bool NobugEngine::IsExiting()
//{
//	return false;
//}

void NobugEngine::InputProcess()
{
	sf::Event event;
	while (_mainWindow.pollEvent(event))
	{
		
		if (event.type == sf::Event::Closed)
			_mainWindow.close();
	}
}

void NobugEngine::GameLoop()
{
	sf::Event event;
	while (_gameState == Initialzed)
	{
		
		// get input

		// update
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= sf::Time::Zero;

			// update game objects
			GM->Update(TimePerFrame);
			
			// update physics
			//_physics->UpdatePhysics(TimePerFrame);

			// update AI

			


			// render
			_mainWindow.clear();
			Render();
			_mainWindow.display();

			// play audio 
		}
		
	
			
		

	}
	
	//	_splashScreen.Show(_mainWindow);

	//	while (_mainWindow.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::EventType::KeyPressed
	//			|| event.type == sf::Event::EventType::MouseButtonPressed
	//			|| event.type == sf::Event::EventType::Closed) {
	//			_gameState = Exiting;
	//		}
	//	}
	_mainWindow.clear();
}

void NobugEngine::Render() {
	
	for (std::map<int, GameObject*>::iterator i = GM->m_Objects.begin(); i != GM->m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (Renderer* r = dynamic_cast<Renderer*>((*j))) {
				r->Render(_mainWindow, i->second);
			}
		}
	}
	

}