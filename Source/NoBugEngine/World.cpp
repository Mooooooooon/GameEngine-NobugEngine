#include "World.h"
#include <iostream>

World::World(Physics* phy, GameObjectManager* gm) {
	_physicsEngine = phy;
	_gameObjectManager = gm;

}


void World::Start() {



	GameObject* backgroundimage = _gameObjectManager->CreateObject();

	Renderer* bgImageRenderer = new Renderer("../../Assets/Images/bg.png");

	bgImageRenderer->sprite.setScale(500, 500);
	backgroundimage->AddComponent(bgImageRenderer);

	std::cout << " created " << std::endl;


}