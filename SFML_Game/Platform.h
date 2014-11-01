#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
public:
	Platform();
	Platform(int xLocation, int yLocation);
	Platform(int xLocation, int yLocation, int xLen, int yLen);
	~Platform();
	sf::RectangleShape getShape();
	float getY();
	float getX();
	int getWidth();
private:
	float xPos;
	float yPos;
	int width;
	int height;
	sf::Vector2f rectSize;
	sf::RectangleShape platSquare;
	sf::Texture platTexture;


};

