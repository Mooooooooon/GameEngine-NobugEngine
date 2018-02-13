#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderwindow)
{
	sf::Texture splashimage;
	if (splashimage.loadFromFile("../../Assets/Images/splash.png") != true) {
		return;
	} 
	/*
	sf::Image img;
	img.create(640, 480, sf::Color::Black);
	splashimage.loadFromImage(img);
	*/
	splashimage.setSmooth(true);
	sf::Sprite sprite(splashimage);
	
	resolution = renderwindow.getView().getSize();
	sprite.setScale(resolution.x / sprite.getLocalBounds().width, resolution.y / sprite.getLocalBounds().height);

	
	
	renderwindow.draw(sprite);
	renderwindow.display();

	
}
