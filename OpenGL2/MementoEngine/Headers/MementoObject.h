#pragma once
#include "MementoInstance.h"
#include "../Core/Headers/Transform.h"
#include <iostream>

class MementoObject : public MementoInstance
{
public: 
	virtual void OnLoad() {
		std::cout << "base object load";
	}
	virtual void Pulse() {
		std::cout << "base object pulse";
	}
	virtual void OnDestroy() {
		std::cout << "base object destroy";
	}
	Transform* transform = new Transform();
};