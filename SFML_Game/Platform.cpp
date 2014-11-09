#include "Platform.h"

//Initializes a simple platform with no special qualities
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
//specifies the x location and y location
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
//sets the x&y - location and length
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
	//following 2 lines allow me to see the border of the squares
	//to confirm that it is the right size and stuff
	platSquare.setOutlineColor(sf::Color::Blue);
	platSquare.setOutlineThickness(-2); // negative so it doesnt look bigger
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