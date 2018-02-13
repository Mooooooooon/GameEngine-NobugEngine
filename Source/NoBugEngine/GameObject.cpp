#include "GameObject.h"

GameObject::~GameObject(void) {
	for (unsigned int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}

void GameObject::AddChild(GameObject* ch) {
	children.push_back(ch);
	ch->parent = this;
}

void GameObject::Update(float deltaTime) {
	if (parent) {
		worldTransform = parent->worldTransform*transform;
	}
	else {
		worldTransform = transform;
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(deltaTime);
	}
}