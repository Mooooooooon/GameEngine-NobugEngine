#include "World.h"
#include <iostream>

World::World(Physics* phy, GameObjectManager* gm) {
	_physicsEngine = phy;
	_gameObjectManager = gm;

}


void World::Start() {



	GameObject* backgroundimage = _gameObjectManager->CreateObject();
	Renderer* bgImageRenderer = new Renderer("../../Assets/Images/beige.png");
	//backgroundimage->transform.m_Scale = sf::Vector2f(2.0f, 2.0f);
	bgImageRenderer->sprite.setScale(600 / bgImageRenderer->sprite.getLocalBounds().width,
		700 / bgImageRenderer->sprite.getLocalBounds().height);
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
	GameObject* dood = _gameObjectManager->CreateObject();
	dood->transform.m_Position.x += 100;
	dood->transform.m_Position.y += 200;
	dood->AddComponent(new Renderer("../../Assets/Images/dood.png"));
	Rigidbody* doodrb = new Rigidbody(dood, _physicsEngine, true);
	//doodrb->obeysGravity = false;
	dood->AddComponent(doodrb);

	

	//InputManager* input = new InputManager(box1);
	
	//std::cout << box1->transform.m_Position.x << " " << box1->transform.m_Position.y << std::endl;
	
	
	GameObject* box2 = _gameObjectManager->CreateObject();
	box2->transform.m_Position.x += 250;
	box2->transform.m_Position.y += 600;
	box2->transform.m_Scale = sf::Vector2f(0.25f, 0.25f);
	box2->AddComponent(new Renderer("../../Assets/Images/platform.png"));
	Rigidbody* box2_Rigid = new Rigidbody(box2, _physicsEngine, false);
	box2_Rigid->obeysGravity = false;
	box2_Rigid->mass = 0;
	box2->AddComponent(box2_Rigid);

	
	GameObject* box3 = _gameObjectManager->CreateObject();
	box3->transform.m_Position.x += 150;
	box3->transform.m_Position.y += 500;
	box3->transform.m_Scale = sf::Vector2f(0.25f, 0.25f);
	box3->AddComponent(new Renderer("../../Assets/Images/platform.png"));
	Rigidbody* box3_Rigid = new Rigidbody(box3, _physicsEngine, false);
	box3_Rigid->obeysGravity = false;
	box3_Rigid->mass = 0;
	box3->AddComponent(box3_Rigid);


	std::vector<GameObject*> platforms;
	
	/*
	for (int i = 0; i < 1; i++) {
		GameObject* box3 = _gameObjectManager->CreateObject();
		box3->transform.m_Position.x += rand() % 200;
		box3->transform.m_Position.y += 600 - i * 100;
		box3->transform.m_Scale = sf::Vector2f(0.25f, 0.25f);
		box3->AddComponent(new Renderer("../../Assets/Images/platform.png"));
		Rigidbody* box3r = new Rigidbody(box3, _physicsEngine, false);
		box3r->obeysGravity = false;
		box3r->mass = 0;
		box3->AddComponent(box3r);


		platforms.push_back(box3);


	}
	*/
	
	



}