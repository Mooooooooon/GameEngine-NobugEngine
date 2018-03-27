#pragma once
#ifndef Rigidbody_h
#define Rigidbody_h
#include "Transform.h"

#include <SFML\Window.hpp>
//#include "Physics.h"
#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Renderer.h"

class GameObject;
class Physics;

class Rigidbody : public BaseComponent 
{
public:
	
	friend Physics;

	struct AABB
	{
		sf::Vector2f tLeft;
		sf::Vector2f bRight;
	};

	AABB aabb;

	float mass = 1.0f;
	float bounciness = 0.5f;
	bool obeysGravity = true;
	sf::Vector2f gravity = sf::Vector2f(0, 20.0f);
	sf::Vector2f currentVelocity;
	sf::Vector2f maxVelocity = sf::Vector2f(30.0f, 30.0f);
	Rigidbody(GameObject* go, Physics* engine, bool iskinematic);
	
	bool grounded = false;
	bool isKinematic;
	

	void AddForce(sf::Vector2f force);

	void Stop();
	bool IsGrounded();
	void SetAABB();
	void Start();
	void Integrate(sf::Time dT);

	GameObject* myParent;

	sf::Vector2f totalForces;
	
	Physics* PhysicsEngine;

	Transform& GetTransform();
};


#endif