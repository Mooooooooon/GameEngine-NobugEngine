#pragma once

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include "BaseComponent.h"
#include "Transform.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include "Rigidbody.h"

class Physics;
class GameObject : public sf::Transformable {
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) {
	}

	int GetObjectID() const { return m_UniqueID; }

	void AddComponent(BaseComponent* component);


	void SetParent(GameObject& parent) { m_Parent = &parent; }
	void AddChild(GameObject* child);

	void Update(sf::Time dt);
	void Awake();
	void Start();
	void LateUpdate(sf::Time dt);


	Transform transform;  
	std::vector<BaseComponent*> m_Components;
	sf::Transform worldTransform;


	int m_UniqueID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	
	
	 
	

};

#endif