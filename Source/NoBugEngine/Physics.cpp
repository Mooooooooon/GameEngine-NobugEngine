#include "Physics.h"
#include "Rigidbody.h"


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
		Rigidbody* rb_A = *j;
		for (std::vector<Rigidbody*>::iterator i = j; i != rigidBodies.end(); ++i)
		{
			Rigidbody* rb_B = *i;

			if (rb_A != rb_B) {

				CollisionPair pair;
				CollisionInfo info;
				pair.rigidBodyA = *rb_A;
				pair.rigidBodyB = *rb_B;

				//sf::Vector2f distance = rb_B->m_gameObject->transform.m_Position - rb_A->m_gameObject->transform.m_Position;

				sf::Vector2f halfSizeA = (rb_A->aabb.bRight - rb_A->aabb.tLeft) * 0.5f;
				sf::Vector2f halfSizeB = (rb_B->aabb.bRight - rb_B->aabb.tLeft) * 0.5f;

				sf::Vector2f distance = (rb_B->myParent->transform.m_Position + halfSizeB) - (rb_A->myParent->transform.m_Position + halfSizeA);
				sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);

				std::cout << " dist " << distance.x << ", " << distance.y << " +  gap " << gap.x << ", " << gap.y << std::endl;
				if (gap.x < 0 && gap.y < 0) {

					//Collide
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
							info.collisionNormal = sf::Vector2f(0.0f, -1.0f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(0.0f, 1.0f);
						}
						info.penetration = gap.y;
					}

					collisions[pair] = info;

				}
				else if (collisions.find(pair) != collisions.end()) {
					//std::cout << "removed" << std::endl;
					//collisions.erase(pair);
				}

			}

		}

	}
}

void Physics::ResolveCollisions()
{
	for (std::map<CollisionPair, CollisionInfo>::iterator it = collisions.begin(); it != collisions.end(); ++it) {
		
		
		float minBounce = fmin(it->first.rigidBodyA.bounciness, it->first.rigidBodyB.bounciness);
		float velAlongNormal = dot(it->first.rigidBodyB.currentVelocity - it->first.rigidBodyA.currentVelocity, collisions[it->first].collisionNormal);
		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;
		float invMassA, invMassB;
		if (it->first.rigidBodyA.mass == 0)
			invMassA = 0;
		else
			invMassA = 1 / it->first.rigidBodyA.mass;

		if (it->first.rigidBodyB.mass == 0)
			invMassB = 0;
		else
			invMassB = 1 / it->first.rigidBodyB.mass;

		j /= invMassA + invMassB;

		sf::Vector2f impulse = j * collisions[it->first].collisionNormal;
		CollisionPair p = it->first;
		// ... update velocities
		Rigidbody a = it->first.rigidBodyA;
		Rigidbody b = it->first.rigidBodyB;
		a.AddForce(impulse / 0.001f);
		b.AddForce(-impulse / 0.001f);
	

		if (abs(collisions[it->first].penetration) > 0.01f) {
			PositionalCorrection(it->first);
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
	//CheckCollisions();
	//ResolveCollisions();
}

void Physics::FixedUpdate(sf::Time dt)
{
	UpdatePhysics(dt);
}