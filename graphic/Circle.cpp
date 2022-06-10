#include"Circle.h"
#include <iostream>

Circle::Circle()
{
	loadTexture();
	currentShape.setRadius(80);
	currentShape.setFillColor(sf::Color(0, 255, 255));
	currentShape.setOutlineThickness(2);
	currentShape.setOutlineColor(sf::Color(66, 133, 244));
	currentShape.setPosition(0, 0);
	speed = 4;
	isControl = true;
	currentShape.setTexture(&texture);
}

void Circle::loadTexture()
{
	if (!texture.loadFromFile("Backgr.png"))
	{
		std::cout << "ERROR WHEN LOAD TEXTURE" << std::endl;
	}
}

sf::CircleShape Circle::getshape()
{
	return currentShape;
}

void Circle::KeyPr()
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
		{
			setSizeDown();
		}
	}
}

void Circle::setSizeDown()
{
	if (Radius > 20) {
		Radius = Radius - speed;
		currentShape.setRadius(Radius);
	}
}

void Circle::setSizeUp()
{
	if (Radius < 200) {
		Radius = Radius + speed;
		currentShape.setRadius(Radius);
	}
}

void Circle::setControl(bool a)
{
	this->isControl = a;
}

void Circle::SetSpeed(float speed)
{
	this->speed = speed;
}

void Circle::setRect(float rect_x, float rect_y)
{
	this->rect_x = rect_x;
	this->rect_y = rect_y;
	this->currentShape.setPosition(rect_x, rect_y);
}

void Circle::setRadi(float radious)
{
	this->Radius = radious;
	currentShape.setRadius(Radius);
}

float Circle::getX()
{
	return rect_x;
}

float Circle::getY()
{
	return rect_y;
}
