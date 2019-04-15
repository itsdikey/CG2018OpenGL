#include "../Headers/VBOWrapper.h"

VBO::VBO(GLenum type)
{
	this->type = type;
	glGenBuffers(1, &bufferId);
}

GLuint VBO::getBufferId()
{
	return bufferId;
}

void VBO::bindBuffer()
{
	glBindBuffer(this->type, bufferId);
}

void VBO::unbindBuffer()
{
	glBindBuffer(this->type, NULL);
}

void VBO::setData(GLenum usage, int size, GLvoid* data)
{
	glBufferData(type, size, data, usage);
}


