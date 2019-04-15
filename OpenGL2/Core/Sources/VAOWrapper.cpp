#include "../Headers/VAOWrapper.h"
VAOWrapper::VAOWrapper()
{
	glGenVertexArrays(1, &vaoId);
}


void VAOWrapper::bindBuffer()
{
	glBindVertexArray(vaoId);
}

void VAOWrapper::unbindBuffer()
{
	glBindVertexArray(0);
}

void VAOWrapper::setLayout(Layout* layout)
{
	for (int i = 0; i < layout->getElementCount(); i++)
	{
		glVertexAttribPointer(layout->getIndex(i), layout->getSize(i),
			layout->getType(i), GL_FALSE, layout->getStride(), layout->getOffsetVPtr(i));
		glEnableVertexAttribArray(layout->getIndex(i));
	}
}
