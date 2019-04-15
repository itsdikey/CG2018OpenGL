#pragma once
#include "../../Core/Headers/Core.h"
class Mesh
{
protected:
	ShaderProgram* program;
	vector<VAOWrapper>* vaos;
	vector<RenderComb>* renderComb;
	vector<unsigned int>* associates;
public:
	Mesh* addVao(VAOWrapper vaoWrapper);
	VAOWrapper getVAOAt(int index);
	Mesh* addRenderComb(RenderComb renderComb, int vaoIndex);
	void setProgram(ShaderProgram* program);
	ShaderProgram* getProgram();
	Mesh();
	void render();
};
