#pragma once
#include "../../../glm/glm.hpp"
#include "../../../glm/gtc/matrix_transform.hpp"
#include "../../../glm/gtx/transform.hpp"
#include "../../../glm/ext.hpp"
#include "../../../glm/gtc/quaternion.hpp"
#include "../../../glm/gtx/quaternion.hpp"
class Transform
{
public:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;
	glm::vec3 worldUp = glm::vec3(0, 1, 0);
	glm::vec3 worldLeft = glm::vec3(1, 0, 0);
	glm::vec3 worldFront = glm::vec3(0, 0, 1);
	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::mat4 getTransformMatrix()
	{
		glm::mat4 transform = glm::translate(position)*glm::toMat4(rotation)*glm::scale(scale);
		return transform;
	}

	glm::vec3 rotationAngles()
	{
		return glm::eulerAngles(rotation);
	}

	void rotate(glm::vec3 rotationDelta)
	{
		rotation += glm::quat(rotationDelta);
	}

	void translate(glm::vec3 translationDelta)
	{
		position += translationDelta;
	}
};