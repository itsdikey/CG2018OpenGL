#include "..\Headers\Sample1Scene.h"
Sample1Scene::Sample1Scene()
{
	SphereObject* sphere = new SphereObject();
	addElement(sphere);

	ArcCamera* arc = new ArcCamera();
	MementoScene::mainCamera = arc;

	addElement(arc);
}