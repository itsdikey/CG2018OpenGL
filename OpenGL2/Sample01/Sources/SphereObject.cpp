#include "../Headers/SphereObject.h"

SphereObject::SphereObject()
{
	sphere = new Sphere(1, 16, 32);
	ShaderProgram* program = new ShaderProgram();
	program->initFromFile("Shaders/vertex.glsl", "Shaders/fragment.glsl");
	sphere->setProgram(program);
}

void SphereObject::Pulse()
{
	cout << "tryna render";
	ShaderProgram* shaderProgram = sphere->getProgram();
	shaderProgram->useShader();
	glm::mat4 Model = glm::mat4(1.0f);
	shaderProgram->SetMat4("model", Model);
	shaderProgram->SetMat4("view", MementoApp::getInstance()->getActiveScene()->getActiveCamera()->getViewMatrix());
	shaderProgram->SetMat4("projection", MementoApp::getInstance()->getActiveScene()->getActiveCamera()->getProjectionMatrix());
	shaderProgram->SetVec3("objectColor", 0.8f, 0.0f, 0.0f);
	shaderProgram->SetVec3("lightColor", 1.0f, 1.0f, 1.0f);
	shaderProgram->SetVec3("lightPos", 0, 0, -5);

	sphere->render();
}