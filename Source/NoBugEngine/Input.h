#pragma once


#include "GameObjectManager.h"
#include "SFML/Window.hpp"
#include <map>
#include <vector>
class Physics;

enum Action
{
	MoveLeft,
	MoveRight,
	MoveUp,
	MoveDown,
	None,
};

class InputManager {

public:
	InputManager(GameObjectManager* gm);
	//InputManager(GameObject* go);

	void CheckInput(sf::Time dt);

	void HandleInput(sf::Time dt);

	std::map<sf::Keyboard::Key, Action>	mKeyBinding;
	Action currentAction;
	GameObjectManager* _gm;
	GameObject* gObject;
	void Awake();
	void Start();
	void Update();
	void LateUpdate();

};