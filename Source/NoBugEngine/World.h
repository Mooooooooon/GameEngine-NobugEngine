#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "GameObjectManager.h"
#include "Physics.h"

class World
{
public:
	World();
	~World();
	
	GameObjectManager* _gameObjectManager;
	Physics* PhysicsEngine;

private:

};
