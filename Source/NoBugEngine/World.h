#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "GameObjectManager.h"
#include "Audio.h"
#include "Physics.h"
#include "Renderer.h"

class World
{
public:
	
	GameObjectManager* _gameObjectManager;
	Physics* _physicsEngine;

	World(Physics* phy, GameObjectManager* gm);

	
	void Start();
	
private:

};

