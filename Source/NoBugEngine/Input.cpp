#include "Input.h"
#include <iostream>


InputManager::InputManager()
{
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;
	
}
/*
InputManager::InputManager(GameObject* go)
{
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;
	gObject = go;
}
*/

void InputManager::CheckInput(sf::Time dt)
{
	for (std::map<sf::Keyboard::Key, Action>::iterator i = mKeyBinding.begin(); i != mKeyBinding.end(); ++i) {
		if (sf::Keyboard::isKeyPressed(i->first)) {
			currentAction = i->second;
		}
		else {
			currentAction = None;
		}

		switch (currentAction)
		{
		case MoveLeft:
			std::cout << "Left" << std::endl;
			//gObject->transform.m_Position.x -= dt.asSeconds();
			break;
		case MoveRight:
			std::cout << "Right" << std::endl;
			//gObject->transform.m_Position.x += dt.asSeconds();
			break;
		case MoveUp:
			std::cout << "Up" << std::endl;
			//gObject->transform.m_Position.y -= dt.asSeconds();
			break;
		case MoveDown:
			std::cout << "Down" << std::endl;
			//gObject->transform.m_Position.y += dt.asSeconds();
			break;
		case None:
			std::cout << "None" << std::endl;
			break;
		default:
			break;
		}

	}
}

void InputManager::HandleInput(sf::Time dt)
{
}
