#include <iostream>

#include <gl/glew.h>

#include "glfw/glfw3.h"

int main(const char* argv, int argc) {

	
	if (!glfwInit()) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "SimplexEngine", NULL, NULL);

	if (!window)
		glfwTerminate();

	glfwMakeContextCurrent(window);

	glewInit();

	float rotAng = 0;

	float vericies[] = {0.0f, 0.5f, 0.0f,
						0.5f,-0.5f, 0.0f,
						-0.5f, -0.5f, 0.0f};

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		unsigned int ba;

		glGenBuffers(1, &ba);

		glBindBuffer(GL_ARRAY_BUFFER, ba);

		glEnableVertexAttribArray(0);

		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vericies, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();
	return 0;
}