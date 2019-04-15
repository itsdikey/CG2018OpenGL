#pragma once
#include "GL\glew.h"
#include "Indices.h"
class RenderComb
{
private:
	GLenum renderType;
	Indice* indice;
public:
	RenderComb(GLenum renderType);
	void setIndices(Indice* indice);
	int getTriangleCount();
	void drawElems();
};