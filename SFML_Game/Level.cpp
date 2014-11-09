#include "Level.h"
#include "Platform.h"
//#include <SFML\Graphics.hpp>
#include <iostream>
class Platform;

Level::Level()
{
}
/**
	This initialization gives you a vector of platforms from the given picture
	uses black squares as platform, red as spawn, green as exit(maybe)
*/
Level::Level(sf::Image levelImage)
{
	sf::Vector2u levelDim(levelImage.getSize());
	//this is so that the given image scales to the game screen
	double xRes = 800 / levelDim.x; 
	double yRes = 600 / levelDim.y;
	for (int j = 0; j < levelDim.y; j++)
	{
		for (int i = 0; i < levelDim.x; i++)
		{
			sf::Color pixelColor = levelImage.getPixel(i, j);

			if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0)
			{
				spawnLocX = i*xRes;
				spawnLocY = j*yRes;
			}
			if (pixelColor == sf::Color::Black)
			{
				float platWidth = xRes;
				int xStart = i;
				for (i += 1; i < levelDim.x; i++)
				{
					//this part of the program makes it so that it creates one
					//longer platform instead of a bunch of seprate platforms

					sf::Color subPixelColor = levelImage.getPixel(i, j);
					if (subPixelColor == sf::Color::Black)
					{
						platWidth += xRes;
					}
					else
					{
						break;
					}
				}
				platforms.push_back(Platform(xStart*xRes,j*yRes,platWidth,yRes));
			}
		}
	}
}

Level::~Level()
{
}
