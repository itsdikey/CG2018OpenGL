#pragma once
#include "MementoInstance.h"
#include "MementoObject.h"
#include "Camera.h"
#include <vector>

using namespace std;
class MementoScene : public MementoInstance
{
protected:
	vector<MementoObject*>* mementoOjectList;
	
    bool isLoaded;
public:
	MementoScene();
	void OnLoad();
	void OnDestroy();
    void Pulse();
	void addElement(MementoObject* element);
	void removeElement(MementoObject* element);
	vector<MementoObject*> getObjects();
	Camera* getActiveCamera();
	Camera* mainCamera;
};