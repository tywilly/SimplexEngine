#include "Shader.h"

#include "Community.h"

#include <iostream>
#include <fstream>
#include <string>
#include <GL\glew.h>

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{

	std::string shaderSource = "";

	std::string line;

	std::ifstream vertexFile(vertexShaderPath);

	if (vertexFile.is_open()) {

		while (std::getline(vertexFile, line)) {
			shaderSource = shaderSource + line + "\n";
		}
		vertexFile.close();
	}

	const char *cPtr = shaderSource.c_str();

	GLCall(vertexShaderID = glCreateShader(GL_VERTEX_SHADER));
	GLCall(glShaderSource(vertexShaderID, 1, &cPtr, NULL));
	GLCall(glCompileShader(vertexShaderID));

	shaderSource = "";

	std::ifstream fragFile(fragmentShaderPath);

	if (fragFile.is_open()) {

		while (std::getline(fragFile, line)) {
			shaderSource = shaderSource + line + "\n";
		}
		fragFile.close();
	}

	cPtr = shaderSource.c_str();

	GLCall(fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER));
	GLCall(glShaderSource(fragmentShaderID, 1, &cPtr, NULL));
	GLCall(glCompileShader(fragmentShaderID));

	GLCall(programID = glCreateProgram());

	GLCall(glAttachShader(programID, vertexShaderID));
	GLCall(glAttachShader(programID, fragmentShaderID));

	GLCall(glLinkProgram(programID));

	GLCall(glValidateProgram(programID));

	char errorBuff[1024];
	int errorStrLen = 0;

	GLCall(glGetShaderInfoLog(vertexShaderID, 1024, &errorStrLen, errorBuff));
	if(errorStrLen != 0)
		std::cout << "OpenGL Vertex Shader Compile error: " << errorBuff << std::endl;

	GLCall(glGetShaderInfoLog(fragmentShaderID, 1024, &errorStrLen, errorBuff));
	if (errorStrLen != 0)
		std::cout << "OpenGL Fragment Shader Compile error: " << errorBuff << std::endl;

}

void Shader::bindShader() {
	GLCall(glUseProgram(programID));
}

unsigned int Shader::getProgramID() {
	return programID;
}

Shader::~Shader()
{

	GLCall(glDeleteShader(fragmentShaderID));
	GLCall(glDeleteShader(vertexShaderID));
	GLCall(glDeleteProgram(programID));

}
