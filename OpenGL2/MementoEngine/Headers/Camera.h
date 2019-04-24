#pragma once
#include "../../glm/glm.hpp"
#include "../../glm/ext.hpp"
#include "../Core/Headers/Transform.h"
#include "../Headers/MementoObject.h"
using namespace glm;
class Camera : public MementoObject
{
public:
	virtual mat4 getViewMatrix()
	{
		return glm::lookAt(this->transform->position, this->lookAt, this->transform->up);
	}
	virtual mat4 getProjectionMatrix()
	{
		return projection;
	}
	Camera(float fov, float aspectRation, float near, float far);
	void setLookAt(vec3 _lookAt);
	virtual void Pulse()
	{
		std::cout << "base pulse";
	}
	virtual void OnLoad()
	{

	}
	virtual void OnDestroy()
	{

	}
protected:
	mat4 projection;
	vec3 lookAt;
};