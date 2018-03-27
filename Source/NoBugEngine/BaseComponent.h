#pragma once
#include <stdio.h>
//#include "Audio.h"
//#include "Renderer.h"
//#include "Rigidbody.h"




class BaseComponent {
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
};
