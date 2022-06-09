#include "Cross.h"
#include <iostream>

Cross::Cross()
{
	loadTexture();
	currentShape.setRadius(20);
	currentShape.setPointCount(8);
	currentShape.setFillColor(sf::Color(255, 255, 255));
	currentShape.setPosition(0, 0);
	isControl = true;
	currentShape.setTexture(&texture);
}

void Cross::loadTexture()
{
	if (!texture.loadFromFile("cross.png"))
	{
		std::cout << "ERROR WHEN LOAD TEXTURE" << std::endl;
	}
}

sf::CircleShape Cross::getshape()
{
	return currentShape;
}

void Cross::KeyPr()
{
	if (isControl) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rect_x = rect_x - speed;
			currentShape.setPosition(rect_x, rect_y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rect_x = rect_x + speed;
			currentShape.setPosition(rect_x, rect_y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rect_y = rect_y - speed;
			currentShape.setPosition(rect_x, rect_y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rect_y = rect_y + speed;
			currentShape.setPosition(rect_x, rect_y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
		{
			setSizeUp();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			setSizeDown();
		}
	}
}

void Cross::setSizeDown()
{
	if (Edge > 20) {
		Edge = Edge - 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(4);
	}
}

void Cross::setSizeUp()
{
	if (Edge < 200) {
		Edge = Edge + 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(4);
	}
}

void Cross::setControl(bool a)
{
	this->isControl = a;
}

void Cross::SetSpeed(float speed)
{
	this->speed = speed;
}

void Cross::setRect(float rect_x, float rect_y)
{
	this->rect_x = rect_x;
	this->rect_y = rect_y;
	this->currentShape.setPosition(rect_x, rect_y);
}

void Cross::setEdge(float radious)
{
	this->Edge = radious;
	currentShape.setRadius(Edge);
	currentShape.setPointCount(4);
}