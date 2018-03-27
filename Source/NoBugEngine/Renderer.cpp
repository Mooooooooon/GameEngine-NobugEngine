#include "Renderer.h"
#include <iostream>


Renderer::Renderer(std::string imagepath) {

	if (texture.loadFromFile(imagepath) != true) {
		std::cout << imagepath << " << cannot find image" << std::endl;
		return;

	}

	sprite.setTexture(texture);
	
	bounds.center = sf::Vector2f(sprite.getOrigin().x, sprite.getOrigin().y);
	bounds.ext = sf::Vector2f(sprite.getLocalBounds().width * 0.5f, sprite.getLocalBounds().height * 0.5f);
}

void Renderer::Awake()
{
}

void Renderer::Start()
{
}

void Renderer::Update()
{
}

void Renderer::LateUpdate()
{
}

void Renderer::Render(sf::RenderWindow & window, GameObject * gameobject)
{
	std::cout << "drawing " << gameobject->transform.m_Position.x << gameobject->transform.m_Position.y << std::endl;
	sprite.setPosition(gameobject->transform.m_Position.x,gameobject->transform.m_Position.y);
	//sprite.setRotation(gameobject->transform.m_Rotation);
	sprite.setScale(gameobject->transform.m_Scale.x, gameobject->transform.m_Scale.y);

	
	window.draw(sprite, gameobject->worldTransform);

}

