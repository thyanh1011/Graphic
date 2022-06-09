#pragma once
#pragma once
#ifndef CROSS_H_
#define CROSS_H_
#include <SFML/Graphics.hpp>

class Cross
{
public:
	Cross();
	~Cross() { ; };

	void KeyPr();
	void SetSpeed(float speed);
	void setSizeUp();
	void setSizeDown();
	void setControl(bool a);
	void setRect(float rect_x, float rect_y);
	void setEdge(float radious);
	void loadTexture();
	sf::CircleShape getshape();

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