#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class SplashScreen
{
public:
	void Show(sf::RenderWindow& renderwindow);
private:
	sf::Vector2f resolution;

};
