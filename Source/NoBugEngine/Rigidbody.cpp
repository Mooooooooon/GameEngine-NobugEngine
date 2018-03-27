#include "Rigidbody.h"
#include "Physics.h"
#include "GameObject.h"
#include <iostream>


Rigidbody::Rigidbody(GameObject * go, Physics * engine, bool iskinematic)
{
	myParent = go;
	PhysicsEngine = engine;
	isKinematic = iskinematic;
	engine->AddRigidBody(this);
	
}

void Rigidbody::AddForce(sf::Vector2f force)
{
	totalForces = sf::Vector2f(totalForces.x + force.x, totalForces.y + force.y);
}

void Rigidbody::Stop()
{
	currentVelocity = sf::Vector2f(0.0f, 0.0f);
	totalForces = sf::Vector2f(0.0f, 0.0f);
}

bool Rigidbody::IsGrounded()
{
	//grounded = PhysicsEngine->IsGrounded(this);
	return grounded;
}

void Rigidbody::SetAABB()
{
	float width = 1;
	float height = 1;

	for (std::vector<BaseComponent*>::iterator j = myParent->m_Components.begin(); j != myParent->m_Components.end(); ++j) {
		if (Renderer* r = dynamic_cast<Renderer*>((*j))) {
			width = r->texture.getSize().x * myParent->transform.m_Scale.x;
			height = r->texture.getSize().y * myParent->transform.m_Scale.y;
		}
	}

	aabb.tLeft = myParent->transform.m_Position;
	aabb.bRight = myParent->transform.m_Position + sf::Vector2f(width, height);
}

void Rigidbody::Start()
{
	SetAABB();
	//engine = GameObject.FindWithTag("PhysicsEngine").GetComponent<PhysicsEngine>();

	//PhysicsEngine->AddRigidBody(this);
}



void Rigidbody::Integrate(sf::Time dT)
{
	
	if (obeysGravity && !IsGrounded()) {
		//std::cout << "gravity" << std::endl;
		AddForce(gravity);
	}
	else {
		if (abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
	}



	sf::Vector2f acceleration = totalForces / mass;
	if (mass == 0)
		acceleration = sf::Vector2f(0,0);

	currentVelocity += acceleration * dT.asSeconds();

	sf::Vector2f temp = myParent->transform.m_Position;

	temp += currentVelocity * dT.asSeconds();
	myParent->transform.m_Position = temp;

	//std::cout << "Force " << totalForces.y << std::endl;
	//std::cout << "P " << myParent->transform.m_Position.x << myParent->transform.m_Position.y << std::endl;
	SetAABB();

	totalForces = sf::Vector2f(0, 0);
}