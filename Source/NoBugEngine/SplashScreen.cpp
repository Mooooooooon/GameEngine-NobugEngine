#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & window)
{
	sf::Texture splashimage;
	if (splashimage.loadFromFile("Images/SplashScreen.png") != true) {
		return;
	}

	sf::Sprite sprite(splashimage);
	

	
	
	window.draw(sprite);
	window.display();

	sf::Event ev;
	while (NobugEngine::_gameState != NobugEngine::Uninitialized)
	{

	}
}
