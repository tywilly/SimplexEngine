#pragma once
#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"

class Entity :
	public GameObject
{
public:
	Entity(float x, float y, float z);
	virtual ~Entity();

	void onDraw();
	void setShader(Shader* shader);

	Mesh* getMesh();

private:
	Mesh* mesh;
	Shader* shader;
};

