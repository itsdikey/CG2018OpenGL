#ifndef VBOCore
#define VBOCore
#endif
#pragma once
#include <vector>
#include <GL\glew.h>
using namespace std;
class VBO
{
private:
	GLuint bufferId;
	GLenum type;
public:
	VBO(GLenum type);
	GLuint getBufferId();

	void bindBuffer();
	//remember to use only when really needed 
	void unbindBuffer();
	//call bindBuffer before
	void setData(GLenum usage,int size, GLvoid* data);
};