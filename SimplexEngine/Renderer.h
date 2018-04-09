#pragma once

#include "Community.h"

#define ASSERT(x) if((x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLCheckError(#x, __LINE__));

static void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static bool GLCheckError(const char* func, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "OpenGL Error " << std::hex << error << " on " << func << " line " << line << std::endl;
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

