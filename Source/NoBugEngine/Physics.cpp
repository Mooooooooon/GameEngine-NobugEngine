#include "Physics.h"


void Physics::AddRigidBody(Rigidbody rigidBody)
{
	rigidBodies.push_front(rigidBody);
}

void Physics::IntegrateBodies(sf::Time dt)
{
	for each(Rigidbody rb in rigidBodies) {
		rb.Integrate(dt);
	}
}

bool Physics::IsGrounded(Rigidbody rigidBody)
{
	for each(Rigidbody rb in rigidBodies) {
		if (rb != rigidBody) {
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
//
//void Physics::CheckCollisions()
//{
//	for (Rigidbody bodyA : rigidBodies) {
//		for each(Rigidbody bodyB in rigidBodies) {
//			if (bodyA != bodyB) {
//				CollisionPair pair = CollisionPair();
//				CollisionInfo colInfo = CollisionInfo();
//				pair.rigidBodyA = bodyA; pair.rigidBodyB = bodyB;
//				
//				sf::Vector2f distance = bodyB.transform.position - bodyA.transform.position;
//
//				sf::Vector2f halfSizeA = (bodyA.aabb.tRight - bodyA.aabb.bLeft) / 2.0f;
//				sf::Vector2f halfSizeB = (bodyB.aabb.tRight - bodyB.aabb.bLeft) / 2.0f;
//
//				sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);
//
//				// Seperating Axis Theorem test
//				if (gap.x < 0 && gap.y < 0) {
//					auto search = collisions.find(pair);
//
//					if (search != collisions.end()) {
//						collisions.erase(pair);
//					}
//
//					if (gap.x > gap.y) {
//						if (distance.x > 0) {
//							// ... Update collision normal
//							colInfo.collisionNormal = sf::Vector2f(1, 0);
//						}
//						else {
//							// ... Update collision normal
//							colInfo.collisionNormal = sf::Vector2f(0, 0);
//						}
//						colInfo.penetration = gap.x;
//					}
//					else {
//						if (distance.y > 0) {
//							// ... Update collision normal
//							colInfo.collisionNormal = sf::Vector2f(0, 1);
//						}
//						else {
//							// ... Update collision normal
//							colInfo.collisionNormal = sf::Vector2f(0, -1);
//						}
//						colInfo.penetration = gap.y;
//					}
//					collisions.insert(std::pair<CollisionPair, CollisionInfo>(pair, colInfo));
//					
//				}
//				else if (collisions.find(pair) != collisions.end()) {
//					collisions.erase(pair);
//				}
//
//			}
//		}
//	}
//}
/*
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

		// ... update velocities
		it->first.rigidBodyA.currentVelocity -= 1 / it->first.rigidBodyA.mass * impulse;
		it->first.rigidBodyB.currentVelocity += 1 / it->first.rigidBodyB.mass * impulse;

		if (abs(collisions[it->first].penetration) > 0.01f) {
			PositionalCorrection(it->first);
		}
	}
}

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