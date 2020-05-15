#pragma once

#ifndef __SimplexEngine_H__
#define __SimplexEngine_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SceneManager.h"
#include "Renderer.h"

class SimplexEngine
{
public:
	SimplexEngine();
	virtual ~SimplexEngine();

	virtual void onStartup() = 0;
	virtual void onShutdown() = 0;

	int startEngine();

private:
	Renderer renderer;
	SceneManager sceneManager;
	GLFWwindow* windowID;

	void initEngine();
	void startGameLoop();

};

#endif
