#include "Physics.h"
#include "Rigidbody.h"
#include <iostream>

void Physics::AddRigidBody(Rigidbody* rigidBody)
{
	rigidBodies.push_back(rigidBody);
}

void Physics::IntegrateBodies(sf::Time dt)
{
	for (Rigidbody* rb : rigidBodies) {
		rb->Integrate(dt);
	}
}


void Physics::CheckCollisions()
{

	for (std::vector<Rigidbody*>::iterator j = rigidBodies.begin(); j != rigidBodies.end(); ++j)
	{
		Rigidbody* rigidBodyA = *j;
		for (std::vector<Rigidbody*>::iterator i = j; i != rigidBodies.end(); ++i)
		{
			Rigidbody* rigidBodyB = *i;

			if (rigidBodyA != rigidBodyB) {
				CollisionPair pair;
				CollisionInfo info;
				pair.rigidBodyA = rigidBodyA;
				pair.rigidBodyB = rigidBodyB;

				//sf::Vector2f distance = rb_B->m_gameObject->transform.m_Position - rb_A->m_gameObject->transform.m_Position;

				sf::Vector2f halfSizeA = (rigidBodyA->aabb.bRight - rigidBodyA->aabb.tLeft) * 0.5f;
				sf::Vector2f halfSizeB = (rigidBodyB->aabb.bRight - rigidBodyB->aabb.tLeft) * 0.5f;

				sf::Vector2f distance = (rigidBodyB->myParent->transform.m_Position + halfSizeB) - (rigidBodyA->myParent->transform.m_Position + halfSizeA);
				sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);

				if (gap.x < 0 && gap.y < 0) {
					rigidBodyA->isCollided = true;
					rigidBodyB->isCollided = true;
					//Collide

					std::cout << "collided " << std::endl;
					if (collisions.find(pair) != collisions.end()) {

						collisions.erase(pair);
					}

					if (gap.x > gap.y) {
						if (distance.x > 0) {
							info.collisionNormal = sf::Vector2f(1.0f, 0.0f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(-1.0f, 0.0f);

						}
						info.penetration = gap.x;
					}
					else {
						if (distance.y > 0) {
							info.collisionNormal = sf::Vector2f(0.0f, 1.0f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(0.0f, -1.0f);
						}
						info.penetration = gap.y;
					}

					collisions[pair] = info;

				}
				else if (collisions.find(pair) != collisions.end()) {
					//std::cout << "removed" << std::endl;
					collisions.erase(pair);
				}

			}

		}

	}

	
}

void Physics::ResolveCollisions(sf::Time dt)
{
	for (std::map<CollisionPair, CollisionInfo>::iterator it = collisions.begin(); it != collisions.end(); ++it)
	{

		CollisionPair pair = it->first;

		float minBounce = std::min(pair.rigidBodyA->bounciness, pair.rigidBodyB->bounciness);
		std::cout << "minBounce " << minBounce << std::endl;

		sf::Vector2f v = pair.rigidBodyB->currentVelocity - pair.rigidBodyA->currentVelocity;
		float velAlongNormal = v.x*collisions[pair].collisionNormal.x + v.y*collisions[pair].collisionNormal.y;
		if (velAlongNormal > 0) continue;

		std::cout << "velAlongNorm " << velAlongNormal << std::endl;
		float j = -( 1 + minBounce ) * velAlongNormal;
		std::cout << "j1 " << j << std::endl;
		float invMassA, invMassB;
		if (pair.rigidBodyA->mass == 0) {
			invMassA = 0;
		}
		else {
			invMassA = 1 / pair.rigidBodyA->mass;
		}

		if (pair.rigidBodyB->mass == 0) {
			invMassB = 0;
		}
		else {
			invMassB = 1 / pair.rigidBodyB->mass;
		}

		j /= invMassA + invMassB;

		std::cout << "j " << j << std::endl;


		sf::Vector2f impulse = j * collisions[pair].collisionNormal;

		std::cout << "impulse " << impulse.y << std::endl;
		
		pair.rigidBodyA->AddForce(-impulse/dt.asSeconds());
		pair.rigidBodyB->AddForce(impulse/ dt.asSeconds());

		if (abs(collisions[pair].penetration) > 0.01f) {
			//PositionalCorrection(pair);
		}
	}
}



/*
void Physics::PositionalCorrection(CollisionPair c)
{
	const float percent = 0.2f;

	float invMassA, invMassB;
	if (c.rigidBodyA.mass == 0)
		invMassA = 0;
	else
		invMassA = 1 / c.rigidBodyA.mass;

	if (c.rigidBodyB.mass == 0)
		invMassB = 0;
	else
		invMassB = 1 / c.rigidBodyB.mass;

	sf::Vector2f correction = ((collisions[c].penetration / (invMassA + invMassB)) * percent) * -collisions[c].collisionNormal;

	sf::Vector2f temp = c.rigidBodyA.transform.position;
	temp -= invMassA * correction;
	c.rigidBodyA.transform.position = temp;

	temp = c.rigidBodyB.transform.position;
	temp += invMassB * correction;
	c.rigidBodyB.transform.position = temp;
}



bool Physics::IsGrounded(Rigidbody* rigidBody)
{
for each(Rigidbody rb in rigidBodies) {
if (&rb != rigidBody) {
if (rigidBody.aabb.bLeft.x < rb.aabb.tRight.x
&& rigidBody.aabb.tRight.x > rb.aabb.bLeft.x
&& std::abs(rigidBody.aabb.bLeft.y - rb.aabb.tRight.y) <= groundedTolerance) {
if (std::abs(rigidBody.currentVelocity.y) < groundedTolerance)
return true;
}
}
}
return false;
}



*/

void Physics::UpdatePhysics(sf::Time dt)
{
	IntegrateBodies(dt);
	CheckCollisions();
	ResolveCollisions(dt);
}

void Physics::FixedUpdate(sf::Time dt)
{
	UpdatePhysics(dt);
}