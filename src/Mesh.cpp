#include "Mesh.h"

#include "Common.h"

#include <iostream>


Mesh::Mesh(const float verticies[], const int vertSize, const int* indicies, const int indexSize)
{

	GLCall(glGenVertexArrays(1, &vertexArrayID));
	GLCall(glBindVertexArray(vertexArrayID));

	std::cout << "Mesh " << vertexArrayID << std::endl;

	GLCall(glGenBuffers(1, &vertexBufferID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(float), verticies, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0));

	GLCall(glBindVertexArray(0));

}

unsigned int Mesh::getVertexArrayID() {
	return vertexArrayID;
}

unsigned int Mesh::getVertexBufferID() {
	return vertexBufferID;
}

Mesh::~Mesh()
{
	GLCall(glDeleteVertexArrays(1, &vertexArrayID));
	std::cout << "Del Mesh" << std::endl;
}
