#pragma once

constexpr auto PI = 3.14159265f;
#include"../../MementoEngine/MementoEngine.h"
#include"../../MementoEngine/MementoEngineCore.h"
class ArcCamera : public Camera
{
public:
	void Pulse();
	mat4 getProjectionMatrix()
	{
		//cout << "projection matrix";
		return Camera::getProjectionMatrix();
	}
	mat4 getViewMatrix()
	{
		//cout << "view matrix";
		return Camera::getViewMatrix();
	}
	ArcCamera();
private:
	vec3 currentUp;
	float _camTheta = PI / 2, _camPhi = 0, _camDistance = 6;
	float _angleY, _angleX;
	int _mouseStepSize = 240;
	glm::vec4 distanceFromCenter = glm::vec4(0, 0, 4, 1);
};