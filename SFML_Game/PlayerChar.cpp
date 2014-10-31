#include "PlayerChar.h"
#include "Platform.h"
#include <iostream>

PlayerChar::PlayerChar(int charType)
{
	if (charType == 1)
	{
		charTexture.loadFromFile("Sprites//Red_Char.png");
	}
	else
	{
		charTexture.loadFromFile("Sprites//Green_Char.png");
	}
	charSprite.setTexture(charTexture);
}

PlayerChar::~PlayerChar()
{
}

void PlayerChar::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		xPos += -.1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		xPos += .1;
	}
	yPos += vSpeed;
	charSprite.setPosition(xPos, yPos);
}

void PlayerChar::fall(std::vector <Platform> platforms)
{
	//int i = 0; i < numPlatforms; i++
	for (Platform plat: platforms)
	{
		float plat_yLoc = plat.getY();
		int plat_yLen = 10; 
		//Needs to be changed...
		/**
		Ok, so this checks to see if the player is above the platform, if no, then it
		automatically exits the if statement. If not, it checks to see if the
		bottom of the player will be below the platform once the vSpeed is taken into account
		Used to check to see if the player needs to stop falling
		*/
		if (falling)
		{
			vSpeed += .0001;
			if (yPos + yLen < plat_yLoc && yPos + yLen + vSpeed >= plat_yLoc)
			{
				vSpeed = 0;
				yPos = plat_yLoc - yLen;
				falling = false;
			}
		}
		else //checks to see if it SHOULD be falling
		{
			//check to see if there is a platform below character
		}
	}
	std::cout << vSpeed << std::endl;
}
sf::Sprite PlayerChar::getSprite()
{
	return charSprite;
}