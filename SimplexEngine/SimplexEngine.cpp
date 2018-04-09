#include "SimplexEngine.h"

#include "Community.h"

#include <iostream>

#include "Entity.h"
#include "Shader.h"

void onFramebufferResize(GLFWwindow* window, int w, int h) {
	glViewport(0, 0, w, h);
}

SimplexEngine::SimplexEngine()
{

}

int SimplexEngine::startEngine() {

	this->initEngine();

	this->onStartup();

	this->startGameLoop();

	return 0;
}

void SimplexEngine::initEngine() {

	renderer = Renderer();

	renderer.init();

	glfwInit();

	windowID = glfwCreateWindow(500,500, "SimplexEngine", NULL, NULL);

	glfwSetFramebufferSizeCallback(windowID, &onFramebufferResize);

	if (!windowID) {
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(windowID);

	if (glewInit() != GLEW_OK) {
		std::cout << "FAILED TO INIT GLEW!" << std::endl;
	}

	glfwSwapInterval(60);//Sync to 60 FPS

}

void SimplexEngine::startGameLoop() {

	Shader shader("vertShader.glsl", "fragShader.glsl");

	Entity ent(0,0,0);
	ent.setShader(&shader);

	while (!glfwWindowShouldClose(windowID)) {

		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		ent.onDraw();

		glfwSwapBuffers(windowID);
		glfwPollEvents();
	}

	this->onShutdown();

	glfwTerminate();

	return;
}

SimplexEngine::~SimplexEngine()
{
}
