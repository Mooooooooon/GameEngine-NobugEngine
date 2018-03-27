#include "Input.h"
#include <iostream>


InputManager::InputManager(GameObjectManager* gm)
{
	_gm = gm;
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;
	
}

void Update(sf::Time dt) {

	
}

void InputManager::CheckInput(sf::Time dt)
{
	
	for (std::map<sf::Keyboard::Key, Action>::iterator i = mKeyBinding.begin(); i != mKeyBinding.end(); ++i) {
		
		if (sf::Keyboard::isKeyPressed(i->first)) {
			currentAction = i->second;
		}
		else {
			currentAction = None;
		}
		std::map<int, GameObject*> _objects = _gm->m_Objects;
		std::cout << _objects.size() << std::endl;
		GameObject* player = _objects[1];

		switch (currentAction)
		{
		case MoveLeft:
			std::cout << "Left" << std::endl;
			//for (std::map<int, GameObject*>::iterator j = _objects.begin(); j != _objects.end(); ++j) {

			//}
			player->transform.m_Position.x -= 5;
			std::cout << player->transform.m_Position.x << std::endl;	
			break;
		case MoveRight:
			std::cout << "Right" << std::endl;
			player->transform.m_Position.x += 5;
			
			break;
		case MoveUp:
			std::cout << "Up" << std::endl;
			player->transform.m_Position.y -= 5;
		
			break;
		case MoveDown:
			std::cout << "Down" << std::endl;
			player->transform.m_Position.y += 5;
			
			break;
		case None:
			//std::cout << "None" << std::endl;
			break;
		default:
			break;
		}
		

	}
	HandleInput(dt);
}

void InputManager::HandleInput(sf::Time dt)
{
	std::map<int, GameObject*> _objects = _gm->m_Objects;
	
}
