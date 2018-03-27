#pragma once
#include <stdio.h>
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>
class Physics;

struct Vector2
{
	Vector2() : x(0.0f), y(0.0f) {}

	Vector2(float _x, float _y) : x(_x), y(_y) {}

	float x, y;
};

class Transform : public BaseComponent {
public:
	
	
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	
		
	sf::Vector2f m_Position;
	float m_Rotation;
	sf::Vector2f m_Scale = sf::Vector2f(1.0f,1.0f);
	
	sf::Transform transformMatrix;
};