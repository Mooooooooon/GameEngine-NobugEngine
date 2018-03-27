#pragma once
#ifndef Renderer_h
#define Renderer_h
#include "BaseComponent.h"
#include "SFML/Window.hpp"
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class GameObject;

struct Bounds
{
public:
	sf::Vector2f center;
	sf::Vector2f ext;
	
};

class Renderer : public BaseComponent {
public:
	Renderer(std::string imagepath);
	
	sf::Texture texture;
	sf::Sprite sprite;

	Bounds bounds;

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void Render(sf::RenderWindow& window, GameObject* gameobject);

};

#endif