#pragma once
#include "MementoInstance.h"
#include "MementoObject.h"
#include <vector>

using namespace std;
class MementoScene : public MementoInstance
{
private:
	vector<MementoObject>* mementoOjectList;
    bool isLoaded;
public:
	MementoScene();
	void OnLoad();
	void OnDestroy();
    void Pulse();
	void addElement(MementoObject element);
	void removeElement(MementoObject element);
	vector<MementoObject> getObjects();
};