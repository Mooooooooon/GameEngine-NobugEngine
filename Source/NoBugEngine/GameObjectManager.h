#pragma once

#include <stdio.h>
#include "GameObject.h"
#include "iostream"
#include <map>
#include <list>
#include <iterator>

class GameObjectManager
{
public:

	GameObject* CreateObject();

	void Update(sf::Time dt);
	void Awake();
	void Start();
	//void LateUpdate(sf::Time time);

private:
	std::map<int, GameObject*> m_Objects;

	static int nextObjectID;
};