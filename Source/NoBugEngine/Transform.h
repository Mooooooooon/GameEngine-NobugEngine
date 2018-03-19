#pragma once
#include <stdio.h>
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>


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
	
		
	Vector2 m_Position;
	float m_Rotation;
	Vector2 m_Scale;
	
	sf::Transform transformMatrix;
};