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
	width = 100;
	height = 20;
	rectSize.x = width;
	rectSize.y = height;
	platSquare.setSize(rectSize);
	platSquare.setPosition(xPos, yPos);
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