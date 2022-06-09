#include "Octagon.h"
#include <iostream>

Octagon::Octagon()
{
	speed = 4;
	loadTexture();
	currentShape.setRadius(20);
	currentShape.setPointCount(8);
	currentShape.setFillColor(sf::Color(255, 255, 255));
	currentShape.setOutlineThickness(2);
	currentShape.setOutlineColor(sf::Color(66, 133, 244));
	currentShape.setPosition(0, 0);
	isControl = true;
	currentShape.setTexture(&texture);
}

void Octagon::loadTexture()
{
	if (!texture.loadFromFile("Backgr.png"))
	{
		std::cout << "ERROR WHEN LOAD TEXTURE" << std::endl;
	}
}

sf::CircleShape Octagon::getshape()
{
	return currentShape;
}

void Octagon::KeyPr()
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

void Octagon::setSizeDown()
{
	if (Edge > 20) {
		Edge = Edge - 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(8);
	}
}

void Octagon::setSizeUp()
{
	if (Edge < 200) {
		Edge = Edge + 4;
		currentShape.setRadius(Edge);
		currentShape.setPointCount(8);
	}
}

void Octagon::setControl(bool a)
{
	this->isControl = a;
}

void Octagon::SetSpeed(float speed)
{
	this->speed = speed;
}

void Octagon::setRect(float rect_x, float rect_y)
{
	this->rect_x = rect_x;
	this->rect_y = rect_y;
	this->currentShape.setPosition(rect_x, rect_y);
}

void Octagon::setEdge(float radious)
{
	this->Edge = radious;
	currentShape.setRadius(Edge);
	currentShape.setPointCount(8);
}

float Octagon::getX()
{
	return rect_x;
}

float Octagon::getY()
{
	return rect_y;
}