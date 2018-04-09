#include "Entity.h"

#include "Community.h"

#include <iostream>
#include <string>


Entity::Entity(float x, float y, float z)
{

	float verts[] = {0.0f, 0.5f, 0.0f,
					0.5f, -0.5f, 0.0f,
					-0.5f, -0.5f, 0.0f};
	int index[] = {0,1,2};

	mesh = new Mesh(verts, 9, index, 3);

}

void Entity::onDraw() {

	(*shader).bindShader();

	GLCall(glBindVertexArray((*mesh).getVertexArrayID()));

	GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));

	GLCall(glBindVertexArray(0));

}

void Entity::setShader(Shader* shader) {
	this->shader = shader;
}

Mesh* Entity::getMesh() {
	return mesh;
}

Entity::~Entity()
{
	delete mesh;
}
