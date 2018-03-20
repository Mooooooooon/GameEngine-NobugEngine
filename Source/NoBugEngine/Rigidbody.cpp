#include "Rigidbody.h"

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
	
	return grounded;
}

void Rigidbody::SetAABB()
{
	/*Bounds bound = new Bounds(new sf::Vector2f(0, 0), new sf::Vector2f(1, 1));
	Renderer renderer = GetComponent<Renderer>();

	if (renderer)
	{
		bound = renderer.bounds;
	}

	aabb.bLeft = new sf::Vector2f(bound.center.x - bound.extents.x, bound.center.y - bound.extents.y);
	aabb.tRight = new sf::Vector2f(bound.center.x + bound.extents.x, bound.center.y + bound.extents.y);*/
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
		AddForce(gravity);
	}
	else {
		if (abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
	}



	sf::Vector2f acceleration = totalForces / mass;
	if (mass == 0)
		acceleration = sf::Vector2f(0,0);

	currentVelocity += acceleration * dT.asSeconds();

//	sf::Vector2f temp = transform.position;
//	temp += currentVelocity * dT.asSeconds();
//	transform.position = temp;
	SetAABB();

	totalForces = sf::Vector2f(0, 0);
}