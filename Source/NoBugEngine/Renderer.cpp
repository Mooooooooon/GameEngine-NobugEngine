#include "Renderer.h"


Renderer::Renderer(std::string imagepath) {

	if (texture.loadFromFile(imagepath) != true) {
		std::cout << imagepath << " << cannot find image" << std::endl;
		return;

	}

	sprite.setTexture(texture);

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
	sprite.setPosition(gameobject->getPosition());
	sprite.setRotation(gameobject->transform.m_Rotation);
	sprite.setScale(gameobject->transform.m_Scale.x, gameobject->transform.m_Scale.y);
	window.draw(sprite);
}

