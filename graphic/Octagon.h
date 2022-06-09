#pragma once
#ifndef OCTAGON_H_
#define OCTAGON_H_
#include <SFML/Graphics.hpp>

class Octagon
{
public:
	Octagon();
	~Octagon() { ; };

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