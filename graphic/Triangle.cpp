#include "Triangle.h"
#include <iostream>

Triangle::Triangle()
{
	speed = 4;
	loadTexture();
	currentShape.setRadius(80);
	currentShape.setPointCount(3);
	currentShape.setFillColor(sf::Color(255, 255, 255));
	currentShape.setOutlineThickness(2);
	currentShape.setOutlineColor(sf::Color(66, 133, 244));
	currentShape.setPosition(300, 300);
	isControl = true;
	currentShape.setTexture(&texture);
}

void Triangle::loadTexture()
{
	if (!texture.loadFromFile("Backgr.png"))
	{
		std::cout << "ERROR WHEN LOAD TEXTURE" << std::endl;
	}
}

sf::CircleShape Triangle::getshape()
{
	return currentShape;
}

void Triangle::KeyPr()
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

void Triangle::setSizeDown()
{
	if (Edge > 20) {
		Edge = Edge - 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(3);
	}
}

void Triangle::setSizeUp()
{
	if (Edge < 200) {
		Edge = Edge + 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(3);
	}
}

void Triangle::setControl(bool a)
{
	this->isControl = a;
}

void Triangle::SetSpeed(float speed)
{
	this->speed = speed;
}

void Triangle::setRect(float rect_x, float rect_y)
{
	this->rect_x = rect_x;
	this->rect_y = rect_y;
	this->currentShape.setPosition(rect_x, rect_y);
}

void Triangle::setEdge(float radious)
{
	this->Edge = radious;
	currentShape.setRadius(Edge);
	currentShape.setPointCount(3);
}

float Triangle::getX()
{
	return rect_x;
}

float Triangle::getY()
{
	return rect_y;
}