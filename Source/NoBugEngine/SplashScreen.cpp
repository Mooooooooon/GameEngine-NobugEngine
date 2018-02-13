#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderwindow)
{
	sf::Texture splashimage;
	if (splashimage.loadFromFile("Images/SplashScreen.png") != true) {
		return;
	}

	sf::Sprite sprite(splashimage);
	

	
	
	renderwindow.draw(sprite);
	renderwindow.display();

	
}
