#include "Rectangle.h"
#include <iostream>
Rectangle::Rectangle()
{
	loadTexture();
	currentShape.setRadius(20);
	currentShape.setPointCount(4);
	currentShape.setFillColor(sf::Color(255, 255, 255));
	currentShape.setOutlineThickness(2);
	currentShape.setOutlineColor(sf::Color(66, 133, 244));
	currentShape.setPosition(0, 0);
	speed = 4;
	isControl = true;
	currentShape.setTexture(&texture);
}

void Rectangle::loadTexture()
{
	if (!texture.loadFromFile("Backgr.png"))
	{
		std::cout << "ERROR WHEN LOAD TEXTURE" << std::endl;
	}
}

void Rectangle::KeyPr()
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

void Rectangle::setSizeDown()
{
	if (Edge > 20) {
		Edge = Edge - 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(4);
	}
}

void Rectangle::setSizeUp()
{
	if (Edge < 200) {
		Edge = Edge + 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(4);
	}
}

void Rectangle::setControl(bool a)
{
	this->isControl = a;
}

void Rectangle::SetSpeed(float speed)
{
	this->speed = speed;
}

sf::CircleShape Rectangle::getshape()
{
	return currentShape;
}

void Rectangle::setEdge(float radious)
{
	this->Edge = radious;
	currentShape.setRadius(Edge);
	currentShape.setPointCount(4);
}

void Rectangle::setRect(float rect_x, float rect_y)
{
	this->rect_x = rect_x;
	this->rect_y = rect_y;
	this->currentShape.setPosition(rect_x, rect_y);
}

float Rectangle::getY()
{
	return rect_y;
}

float Rectangle::getX()
{
	return rect_x;
}