#pragma once
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <SFML/Graphics.hpp>

class Triangle
{
public:
	Triangle();
	~Triangle() { ; };

	void KeyPr();
	void SetSpeed(float speed);
	void setSizeUp();
	void setSizeDown();
	void setControl(bool a);
	void setRect(float rect_x, float rect_y);
	void setEdge(float radious);
	void loadTexture();
	sf::CircleShape getshape();

	float getX();
	float getY();

private:
	float Edge;
	float rect_x;
	float rect_y;
	float speed;
	bool isControl;
	sf::CircleShape currentShape;
	sf::Texture texture;
};

#endif