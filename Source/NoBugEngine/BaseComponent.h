#pragma once
#include <stdio.h>
#include "BaseMessage.h"

class BaseComponent {
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
};
