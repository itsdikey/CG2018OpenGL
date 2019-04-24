#include "../Headers/MementoApp.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "..\..\..\Core\Headers\Core.h"
#include "..\..\..\glm\glm.hpp"
#include "..\..\..\glm\ext.hpp"
#ifndef Utils
#define Utils
#include "..\..\..\MementoEngine\Headers\Utils.h"
#endif
#include "../../../Sample01/Headers/Sample1Scene.h"
using namespace std;



void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//MementoApp::getInstance()->getMouse()->setPos(xpos, ypos);
	/*double deltaX = MementoApp::getInstance()->getMouse()->getDeltaX();
	double deltaY = MementoApp::getInstance()->getMouse()->getDeltaY();
	_angleX += PI * deltaY / _mouseStepSize;
	_angleY += PI * deltaX / _mouseStepSize;
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), _angleX, glm::vec3(1, 0, 0));
	rotation = glm::rotate(rotation, _angleY, glm::vec3(0, 1, 0));
	currentUp = rotation * glm::vec4(up, 0.f);
	mousePos = rotation * distanceFromCenter;*/
	//Spherical coordinates have issues on Pi/2 and -Pi/2 where cos(theta) = 0
	/*_camTheta += PI * deltaY / _mouseStepSize;
	_camPhi += PI * deltaX / _mouseStepSize;
	cout << "Cam theta: " << _camTheta<<endl;
	mousePos = Utils::toCartesianFromSphere(_camDistance, _camTheta, _camPhi);*/
	//cout << _angleX << " " << _angleY << " " << endl;
}
GLFWwindow* window;

MementoApp::MementoApp()
{
	//do nothing
}

MementoApp* MementoApp::singletonInstance;

MementoApp* MementoApp::getInstance()
{
	if (!singletonInstance)
	{
		singletonInstance = new MementoApp();
	}
	return singletonInstance;
}

int MementoApp::onInit()
{

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	int windowWidth = 640;
	int windowHeight = 480;
	
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
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

	currentMouse = new Mouse();
	currentMouse->setPos(windowWidth / 2, windowHeight / 2);
	currentMouse->setPos(windowWidth / 2, windowHeight / 2);
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	glClearDepth(-1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_GREATER);

	
	double xPos, yPos;
	activeScene = new Sample1Scene();
	//program->useShader();
	Time::init();
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		Time::Pulse();

	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		activeScene->Pulse();
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR)
		{
			cout << "Error" << endl;
			// Process/log the error.
			cout << err << endl;
		}
		//Swap front and back buffers 
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
		glfwGetCursorPos(window, &xPos, &yPos);
		currentMouse->setPos(xPos, yPos);
	}

	//program->deleteShader();

	glfwTerminate();
	return 0;
}

void MementoApp::onMainCycle()
{

}

void MementoApp::onExit()
{

}

Mouse* MementoApp::getMouse()
{
	return currentMouse;
}

MementoScene * MementoApp::getActiveScene()
{
	return activeScene;
}



