#include "../Headers/Mesh.h"
#include "../../glm/glm.hpp"
#include "../../glm/ext.hpp"
Mesh::Mesh()
{
	this->associates = new vector<unsigned int>();
	this->renderComb = new vector<RenderComb>();
	this->vaos = new vector<VAOWrapper>();
}

Mesh* Mesh::addVao(VAOWrapper vaoWrapper)
{
	this->vaos->push_back(vaoWrapper);
	return this;
}
Mesh* Mesh::addRenderComb(RenderComb renderComb, int vaoIndex)
{
	this->renderComb->push_back(renderComb);
	this->associates->push_back(vaoIndex);
	return this;
}

VAOWrapper Mesh::getVAOAt(int index)
{
	return vaos->at(index);
}
void Mesh::setProgram(ShaderProgram* program)
{
	this->program = program;
}
ShaderProgram* Mesh::getProgram()
{
	return this->program;
}

void Mesh::render()
{
	VAOWrapper activeVao;
	for (int i = 0; i < renderComb->size(); i++)
	{
		activeVao = vaos->at(associates->at(i));
		activeVao.bindBuffer();
		renderComb->at(i).drawElems();
	}

	activeVao.unbindBuffer();
}
