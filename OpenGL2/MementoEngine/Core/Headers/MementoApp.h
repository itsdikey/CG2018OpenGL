#include "../Headers/Mouse.h"
#include "../Headers/Time.h"
#include "../../Headers/MementoScene.h"
#pragma once
class MementoApp
{
private:
	bool isInitialized;
	MementoApp();
	static MementoApp* singletonInstance;
	Mouse* currentMouse;
	MementoScene* activeScene;
public:
	static MementoApp* getInstance();
	int onInit();
	void onMainCycle();
	void onExit();
	Mouse* getMouse();
	MementoScene* getActiveScene();
};