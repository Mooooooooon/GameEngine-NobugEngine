#pragma once
#include "Transform.h"
#include <SFML\Window.hpp>
#include <stdio.h>
#include <vector>
#include <SFML\Graphics.hpp>

class GameObject;
class Physics;

class Rigidbody {
public:
	struct AABB
	{
		sf::Vector2f bLeft;
		sf::Vector2f tRight;
	};

	float mass = 1.0f;
	float bounciness = 0.5f;
	bool obeysGravity = true;
	sf::Vector2f gravity = sf::Vector2f(0, -9.8f);
	sf::Vector2f currentVelocity;
	sf::Vector2f maxVelocity = sf::Vector2f(10.0f, 10.0f);

	bool grounded;
	
	

	AABB aabb;

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

inline bool operator!= (Rigidbody &rb1, Rigidbody &rb2) {
	return !(&rb1 == &rb2);
}