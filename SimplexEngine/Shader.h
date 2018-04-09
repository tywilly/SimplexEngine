#pragma once
class Shader
{
public:
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	virtual ~Shader();

	void bindShader();

	unsigned int getProgramID();

private:
	unsigned int programID;
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
};

