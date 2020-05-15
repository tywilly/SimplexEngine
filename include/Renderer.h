#pragma once

#include "Common.h"
#include <GL/glew.h>

#ifdef SE_DEBUG
    #define GLCall(x) GLClearError(); x; GLCheckError(#x, __LINE__);
#else
    #define GLCall(x) x;
#endif

static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool GLCheckError(const char* func, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "OpenGL Error 0x" << std::hex << error << " on " << func << " line " << line << std::endl;
		return true;
	}
	return false;
}

class Renderer
{
public:
	Renderer();
	~Renderer();

	void init();

	void onDraw();

};

