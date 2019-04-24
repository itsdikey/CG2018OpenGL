#include "../Headers/MementoScene.h"

void MementoScene::Pulse()
{
	for (int i = 0; i < mementoOjectList->size(); i++)
	{
		mementoOjectList->at(i)->Pulse();
	}
}

vector<MementoObject*> MementoScene::getObjects()
{
	return *mementoOjectList;
}

Camera * MementoScene::getActiveCamera()
{
	return mainCamera;
}

MementoScene::MementoScene()
{
	mementoOjectList = new vector<MementoObject*>();
}

void MementoScene::OnLoad()
{
	for (int i = 0; i < mementoOjectList->size(); i++)
	{
		mementoOjectList->at(i)->OnLoad();
	}
	isLoaded = true;
}

void MementoScene::OnDestroy()
{
	for (int i = 0; i < mementoOjectList->size(); i++)
	{
		mementoOjectList->at(i)->OnDestroy();
	}
	isLoaded = false;
}

void MementoScene::addElement(MementoObject* object)
{
	mementoOjectList->push_back(object);
	if (isLoaded)
		object->OnLoad();
}

void MementoScene::removeElement(MementoObject* object)
{
	int index = -1;
	for (int i = 0; i < mementoOjectList->size(); i++)
	{
		if (&mementoOjectList->at(i) == &object)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		object->OnDestroy();
		mementoOjectList->erase(mementoOjectList->begin()+index);
	}
	
}