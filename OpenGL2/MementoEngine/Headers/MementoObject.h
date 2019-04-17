#pragma once
#include "MementoInstance.h"
class MementoObject : public MementoInstance
{
public: 
	void OnLoad();
	void Pulse();
	void OnDestroy();
};