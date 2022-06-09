#pragma once
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <SFML/Graphics.hpp>

class Circle
{
public:
	Circle();
	~Circle() { ; };

	void KeyPr();
	void SetSpeed(float speed);
	void setSizeUp();
	void setSizeDown();
	void setControl(bool a);
	void setRect(float rect_x, float rect_y);
	void setRadi(float radious);
	void loadTexture();
	sf::CircleShape getshape();

	float getX();
	float getY();

private:
	float Radius;
	float rect_x;
	float rect_y;
	float speed;
	bool isControl;
	sf::CircleShape currentShape;
	sf::Texture texture;
};

#endif // !CIRCLE_H_
