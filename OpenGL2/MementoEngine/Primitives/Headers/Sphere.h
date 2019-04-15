#pragma once
#include "../../Headers/Mesh.h"
#include "../../../Core/Headers/Core.h"
class Sphere : public Mesh
{
public:
	Sphere(float radius, int stackCount, int sectorCount);
};