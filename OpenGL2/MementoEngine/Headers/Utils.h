#pragma once
#ifndef MEMENTOUTILS
#define MEMENTOUTILS
#include "../../glm/glm.hpp"

#endif
namespace Utils
{
	//theta is 0 to pi
	//phi is 0 to 2pi
	glm::vec3 toCartesianFromSphere(float r, float theta, float phi)
	{
		float xz = r * sinf(theta);
		float y = r * cosf(theta);
		return glm::vec3(xz*sinf(phi),y, xz*cosf(phi));
	}
}
