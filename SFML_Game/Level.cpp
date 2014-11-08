#include "Level.h"
#include "Platform.h"
//#include <SFML\Graphics.hpp>
#include <iostream>
class Platform;

Level::Level()
{
}

Level::Level(sf::Image levelImage)
{
	sf::Vector2u levelDim(levelImage.getSize());
	double xRes = 800 / levelDim.x; 
	double yRes = 600 / levelDim.y;
	for (int j = 0; j < levelDim.y; j++)
	{
		for (int i = 0; i < levelDim.x; i++)
		{
			sf::Color pixelColor = levelImage.getPixel(i, j);
			//if (pixelColor.r == 255)
			int test = pixelColor.g;
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
