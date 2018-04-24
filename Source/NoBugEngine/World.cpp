#include "World.h"
#include <iostream>

World::World(Physics* phy, GameObjectManager* gm) {
	_physicsEngine = phy;
	_gameObjectManager = gm;

}


void World::Start() {



	GameObject* backgroundimage = _gameObjectManager->CreateObject();
	Renderer* bgImageRenderer = new Renderer("../../Assets/Images/bg.png");
	backgroundimage->transform.m_Scale = sf::Vector2f(2.0f, 2.0f);
	backgroundimage->AddComponent(bgImageRenderer);


	sf::Music music;
	if (!music.openFromFile("../../Assets/Sound/bensound-energy.wav"))
	{
		std::cout << " no music ";
	}
	music.play();


	//backgroundimage->AddComponent(bgmusic);


	//std::cout << "bg created " << std::endl;
	/*
	GameObject* box1 = _gameObjectManager->CreateObject();	
	box1->transform.m_Position.x = 100;
	box1->transform.m_Position.y = 100;
	box1->AddComponent(new Renderer("../../Assets/Images/beige.png"));
	//Rigidbody* box_Rigid = new Rigidbody(box1, _physicsEngine, true);
	//box1->AddComponent(box_Rigid);

	GameObject* box3 = _gameObjectManager->CreateObject();
	box3->transform.m_Position.x = 0;
	box3->transform.m_Position.y = 0;
	box3->AddComponent(new Renderer("../../Assets/Images/beige.png"));
	//Rigidbody* box_Rigid3 = new Rigidbody(box3, _physicsEngine, true);
	box1->AddChild(box3);


	*/
	GameObject* box4 = _gameObjectManager->CreateObject();
	box4->transform.m_Position.x += 100;
	box4->transform.m_Position.y += 200;
	box4->AddComponent(new Renderer("../../Assets/Images/beige.png"));
	Rigidbody* box_Rigid4 = new Rigidbody(box4, _physicsEngine, true);
	//box_Rigid4->obeysGravity = false;
	box4->AddComponent(box_Rigid4);
	

	//InputManager* input = new InputManager(box1);
	
	//std::cout << box1->transform.m_Position.x << " " << box1->transform.m_Position.y << std::endl;
	
	GameObject* box2 = _gameObjectManager->CreateObject();
	box2->transform.m_Position.x += 200;
	box2->transform.m_Position.y += 700;
	box2->transform.m_Scale = sf::Vector2f(2.0f, 1.0f);
	box2->AddComponent(new Renderer("../../Assets/Images/green.png"));
	Rigidbody* box2_Rigid = new Rigidbody(box2, _physicsEngine, false);
	box2_Rigid->obeysGravity = false;
	box2_Rigid->mass = 0;
	box2->AddComponent(box2_Rigid);



}