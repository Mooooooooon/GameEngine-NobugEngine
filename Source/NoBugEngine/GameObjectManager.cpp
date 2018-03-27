#include "GameObjectManager.h"

// Initialize our static unique objectID generator
int GameObjectManager::nextObjectID = 0;

void GameObjectManager::Awake() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Awake();
	}
}

void GameObjectManager::Start() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Start();
	}
}


void GameObjectManager::Update(sf::Time dt) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Update(dt);
	}
}

void GameObjectManager::Render(sf::RenderWindow window)
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		for (std::vector<BaseComponent*>::iterator j = (i->second)->m_Components.begin(); j != (i->second)->m_Components.end(); ++j) {
			if (Renderer* r = dynamic_cast<Renderer*>((*j))) {
				r->Render(window, i->second);
			}
		}
	}
}


GameObject* GameObjectManager::CreateObject()
{
	GameObject* newObj = new GameObject(nextObjectID++);
	m_Objects[newObj->GetObjectID()] = newObj;

	return newObj;
}

