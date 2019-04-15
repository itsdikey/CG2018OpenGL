#include "../Headers/RenderComb.h"

RenderComb::RenderComb(GLenum renderType)
{
	this->renderType = renderType;
}

int RenderComb::getTriangleCount()
{
	if (this->indice == nullptr)
		return 0;

	if (this->renderType == GL_TRIANGLES)
	{
		return this->indice->getLength();
	}

	if (this->renderType == GL_TRIANGLE_FAN || this->renderType == GL_TRIANGLE_STRIP)
	{
		return this->indice->getLength()-2;
	}
}

void RenderComb::setIndices(Indice* indice)
{
	this->indice = indice;
}

void RenderComb::drawElems()
{
	glDrawElements(this->renderType, this->indice->getLength(), GL_UNSIGNED_INT, this->indice->getPointer());
}