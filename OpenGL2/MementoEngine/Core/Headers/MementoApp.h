#pragma once
class MementoApp
{
private:
	bool isInitialized;
	MementoApp();
	static MementoApp* singletonInstance;
public:
	static MementoApp* getInstance();
	int onInit();
	void onMainCycle();
	void onExit();
};