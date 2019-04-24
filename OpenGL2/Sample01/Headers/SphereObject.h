#pragma once

#include"../../MementoEngine/MementoEngine.h"
#include"../../MementoEngine/MementoEngineCore.h"
#include"../../MementoEngine/MementoPrimitives.h"

class SphereObject : public MementoObject
{
public:
	virtual void Pulse();
	SphereObject();
private:
	Sphere* sphere;
	ShaderProgram* program;
};