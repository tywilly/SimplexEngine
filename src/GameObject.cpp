#include "GameObject.h"



GameObject::GameObject()
{
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
}

float GameObject::getX() {
	return x;
}

void GameObject::setX(float x) {
	this->x = x;
}

float GameObject::getY() {
	return y;
}

void GameObject::setY(float y) {
	this->y = y;
}

float GameObject::getZ() {
	return z;
}

void GameObject::setZ(float z) {
	this->z = z;
}

float GameObject::getHeight() {
	return height;
}

void GameObject::setHeight(float height) {
	this->height = height;
}

float GameObject::getWidth() {
	return width;
}

void GameObject::setWidth(float width) {
	this->width = width;
}

GameObject::~GameObject()
{
}
