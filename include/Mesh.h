#pragma once

#include <GL/glew.h>

class Mesh
{
public:
	Mesh(const float verticies[], const int vertSize, const int* indicies, const int indexSize);
	virtual ~Mesh();

	unsigned int getVertexArrayID();
	unsigned int getVertexBufferID();

private:
	float* m_verticies;
	int* m_indicies;

	unsigned int vertexArrayID = 0;
	unsigned int vertexBufferID = 0;

};

