#pragma once
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void onDraw() = 0;

	float getX();
	void setX(float x);

	float getY();
	void setY(float y);

	float getZ();
	void setZ(float z);

	float getHeight();
	void setHeight(float height);

	float getWidth();
	void setWidth(float width);

private:
	float x, y, z;
	float width, height;
};

