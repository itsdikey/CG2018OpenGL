#include "../Headers/ArcCamera.h"
ArcCamera::ArcCamera() : Camera(glm::radians(45.0f),4/3.0f,0.01f,100.0f)
{
	currentUp = this->transform->worldUp;
	this->transform->position = glm::vec3(0, 0, 4);
}

void ArcCamera::Pulse()
{
	cout << endl << "updating pos" << endl;
	double deltaX = MementoApp::getInstance()->getMouse()->getDeltaX();
	double deltaY = MementoApp::getInstance()->getMouse()->getDeltaY();
	_angleX += PI * deltaY / _mouseStepSize;
	_angleY += PI * deltaX / _mouseStepSize;
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), _angleX, glm::vec3(1, 0, 0));
	rotation = glm::rotate(rotation, _angleY, glm::vec3(0, 1, 0));
	this->transform->up = rotation * glm::vec4(transform->worldUp, 0.f);
	this->transform->position = rotation * distanceFromCenter;
}