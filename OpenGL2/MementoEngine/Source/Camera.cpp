#include "../Headers/Camera.h"
Camera::Camera(float fov, float aspectRation, float near, float far)
{
	projection = glm::perspective(fov, aspectRation, near, far);
}

void Camera::setLookAt(vec3 _lookAt)
{
	this->lookAt = _lookAt;
}
