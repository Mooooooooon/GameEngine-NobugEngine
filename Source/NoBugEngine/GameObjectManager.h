#pragma once

#include <stdio.h>
#include "GameObject.h"
#include "BaseComponent.h"
#include "Renderer.h"
#include "iostream"
#include <map>
#include <list>
#include <iterator>
class Physics;
class GameObjectManager
{
public:

	GameObject* CreateObject();

	void Update(sf::Time dt);
	void Awake();
	void Start();
	//void LateUpdate(sf::Time time);
	void Render(sf::RenderWindow window);
	std::map<int, GameObject*> m_Objects;
private:
	

	static int nextObjectID;
};