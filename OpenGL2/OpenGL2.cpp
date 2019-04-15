constexpr auto PI = 3.14159265f;
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "Core\Headers\Core.h"
#include "glm\glm.hpp"
#include "glm\ext.hpp"
#include "MementoEngine\Headers\Mesh.h"
#include "MementoEngine\Primitives\Headers\Sphere.h"
#ifndef Utils
#define Utils
#include "MementoEngine\Headers\Utils.h"
#endif

using namespace std;

float _camTheta = PI/2, _camPhi=0, _camDistance = 6;
float _angleY, _angleX;
double _mouseLastPosX = 320, _mouseLastPosY = 240, _mouseStepSize = 240;
glm::vec3 mousePos;
glm::vec4 distanceFromCenter = glm::vec4(0, 0, 4,1);
glm::vec3 up = glm::vec3(0, 1, 0);
glm::vec3 currentUp=up;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	double deltaX = xpos - _mouseLastPosX;
	double deltaY = ypos - _mouseLastPosY;
	_mouseLastPosX = xpos;
	_mouseLastPosY = ypos;
	_angleX += PI * deltaY / _mouseStepSize;
	_angleY += PI * deltaX / _mouseStepSize;
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), _angleX, glm::vec3(1, 0, 0));
	rotation = glm::rotate(rotation, _angleY, glm::vec3(0, 1, 0));
	currentUp = rotation * glm::vec4(up,0.f);
	mousePos = rotation * distanceFromCenter;
	//Spherical coordinates have issues on Pi/2 and -Pi/2 where cos(theta) = 0
    /*_camTheta += PI * deltaY / _mouseStepSize;
	_camPhi += PI * deltaX / _mouseStepSize;
	cout << "Cam theta: " << _camTheta<<endl;
	mousePos = Utils::toCartesianFromSphere(_camDistance, _camTheta, _camPhi);*/
	cout << _angleX << " " << _angleY <<" "<<endl;
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwSwapInterval(1);
	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	//process mouse inputs
	glfwSetCursorPosCallback(window, mouse_callback);

	mousePos = glm::vec3(0, 0, 4);
	// call glewInit after creating the context...
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}


	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);*/

	glClearDepth(-1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_GREATER);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	ShaderProgram* program = new ShaderProgram();
	program->initFromFile("Shaders/vertex.glsl", "Shaders/fragment.glsl");
	Sphere* sphere = new Sphere(1, 32, 32);
	sphere
		->setProgram(program);


	program->useShader();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
		// Render here 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::mat4 Model = glm::mat4(1.0f);
		glm::mat4 View = glm::lookAt(mousePos,
			glm::vec3(0, 0, 0), currentUp);//center, lookat, up

		glm::mat4 Projection = glm::perspective(glm::radians(45.0f),
			(float)4.0 / (float)3.0, 0.1f, 100.0f);


		program->SetMat4("model", Model);
		program->SetMat4("view", View);
		program->SetMat4("projection", Projection);
		program->SetVec3("objectColor", 0.8f, 0.0f, 0.0f);
		program->SetVec3("lightColor", 1.0f, 1.0f, 1.0f);
		program->SetVec3("lightPos", 0, 0, -5);


	/*	vao->bindBuffer();
		glDrawElements(GL_TRIANGLE_FAN, fanIndices.size(), GL_UNSIGNED_INT, fanIndices.data());
		glDrawElements(GL_TRIANGLE_FAN, lowerFanIndices.size(), GL_UNSIGNED_INT, lowerFanIndices.data());
		glDrawElements(GL_TRIANGLE_STRIP, restOfIndices.size(), GL_UNSIGNED_INT, restOfIndices.data());
	    glDrawElements(GL_POINTS, allIndices.size(), GL_UNSIGNED_INT, allIndices.data());*/

		sphere->render();
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR)
		{
			cout << "Error"<<endl;
			// Process/log the error.
			cout << err<<endl;
		}
		//Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}

	program->deleteShader();
	
	glfwTerminate();
	return 0;
}