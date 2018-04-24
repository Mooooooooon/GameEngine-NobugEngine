#pragma once
#ifndef Physics_h
#define Physics_h
#include "Rigidbody.h"
#include "Transform.h"

#include <list>
#include <map>
#include <cmath>
//#include <vector>
class Rigidbody;


class Physics
{
public:
	
	struct CollisionPair {
		Rigidbody* rigidBodyA;
		Rigidbody* rigidBodyB;

		bool operator<(const CollisionPair& other) const {
			return false;
		}
	};



	struct CollisionInfo {
		sf::Vector2f collisionNormal;
		float penetration;

		bool operator<(const CollisionPair& other) const {
			return false;
		}
	};
	float dot(sf::Vector2f v1, sf::Vector2f v2) {

		return (v1.x * v2.x + v1.y + v2.y);
	}
	float magnitude(sf::Vector2f vector) {
		return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
	}


	
	std::map<CollisionPair, CollisionInfo> collisions;
	std::vector<Rigidbody*> rigidBodies;

	float groundedTolerance = 0.1f;
	void AddRigidBody(Rigidbody* rigidBody);
	bool IsGrounded(Rigidbody rigidBody);
	void UpdatePhysics(sf::Time dt);
private:
	

	
	
	void CheckCollisions();
	void ResolveCollisions(sf::Time dt);
	void PositionalCorrection(CollisionPair c);

	void IntegrateBodies(sf::Time dt);
	
	void FixedUpdate(sf::Time dt);
};

#endif
