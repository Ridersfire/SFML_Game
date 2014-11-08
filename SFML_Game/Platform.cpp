#include "Platform.h"

Platform::Platform()
{
	xPos = 0;
	yPos = 0;
	width = 100;
	height = 20;
	rectSize.x = width;
	rectSize.y = height;
	platSquare.setSize(rectSize);
	platSquare.setPosition(xPos, yPos);
}
Platform::Platform(int xLocation, int yLocation)
{
	xPos = xLocation;
	yPos = yLocation;
	width = 20;
	height = 20;
	rectSize.x = width;
	rectSize.y = height;
	platSquare.setSize(rectSize);
	platSquare.setPosition(xPos, yPos);
}
Platform::Platform(int xLocation, int yLocation, int xLen, int yLen)
{
	xPos = xLocation;
	yPos = yLocation;
	width = xLen;
	height = yLen;
	rectSize.x = width;
	rectSize.y = height;
	platSquare.setSize(rectSize);
	platSquare.setPosition(xPos, yPos);
	platSquare.setOutlineColor(sf::Color::Blue);
	platSquare.setOutlineThickness(-2);
}

Platform::~Platform()
{
}

sf::RectangleShape Platform::getShape()
{
	return platSquare;
}

float Platform::getY()
{
	return yPos;
}
float Platform::getX()
{
	return xPos;
}
int Platform::getWidth()
{
	return width;
}