#pragma once
#include "BaseComponent.h"
#include "SFML/Window.hpp"
#include "GameObject.h"
#include <SFML\Graphics.hpp>



class Renderer : public BaseComponent {
public:
	Renderer(std::string imagepath);
	
	sf::Texture texture;
	sf::Sprite sprite;

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void Render(sf::RenderWindow& window, GameObject* gameobject);

};