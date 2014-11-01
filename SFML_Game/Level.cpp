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
	for (int i = 0; i < levelDim.x; i++)
	{
		for (int j = 0; j < levelDim.y; j++)
		{
			sf::Color pixelColor = levelImage.getPixel(i, j);
			//if (pixelColor.r == 255)
			int test = pixelColor.g;
			if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0)
				std::cout << i << " " << j << std::endl;
			if (pixelColor == sf::Color::Black)
			{
				platforms.push_back(Platform(i*xRes,j*yRes));
			}
		}
	}
}

Level::~Level()
{
}
