#pragma once
#include <GL/glew.h>
#include "Layout.h"
class VAOWrapper
{
private:
	unsigned int vaoId;
public:
	VAOWrapper();
	void bindBuffer();
	void unbindBuffer();
	void setLayout(Layout* layout);
};