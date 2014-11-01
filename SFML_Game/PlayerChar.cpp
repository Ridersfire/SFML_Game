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

void PlayerChar::update(std::vector <Platform> platforms)
{
	move();
	fall(platforms);
}

void PlayerChar::move()
{
	if (sf::Keyboard::isKeyPressed(KEY_MOVELEFT))
	{
		xPos += -5;
	}
	else if (sf::Keyboard::isKeyPressed(KEY_MOVERIGHT))
	{
		xPos += 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//Insert Skill here
	}
	if (sf::Keyboard::isKeyPressed(KEY_JUMP) && !falling) vSpeed = -jumpSpeed;
	yPos += vSpeed;
	charSprite.setPosition(xPos, yPos);
}

void PlayerChar::fall(std::vector <Platform> platforms)
{
	falling = true;
	//int i = 0; i < numPlatforms; i++
	for (Platform plat: platforms)
	{
		float plat_yLoc = plat.getY();
		float plat_xLoc = plat.getX();
		int plat_yLen = 10; 
		int plat_xLen = plat.getWidth();

		/**
		Top Left - xPos,yPos
		Top Right - xPos+xLen
		Bottom Left - xPos, yPos+yLen
		Bottom Right - xPos + xLen, yPos + yLen
		*/
		//Needs to be changed...
		/**
		Ok, so this checks to see if the player is above the platform, if no, then it
		automatically exits the if statement. If not, it checks to see if the
		bottom of the player will be below the platform once the vSpeed is taken into account
		Used to check to see if the player needs to stop falling
		*/

		if (yPos + yLen <= plat_yLoc && yPos + yLen + vSpeed >= plat_yLoc)
		{
			if (xPos + xLen >= plat_xLoc && xPos <= plat_xLoc + plat_xLen)
			{
				yPos = plat_yLoc - yLen;
				falling = false;
			}
		}
		//yPos = smallestYpos;
		
		if(falling) //checks to see if it SHOULD be falling
		{
			//check to see if there is a platform below character
			//vSpeed += .0001;
		}
	}
	if (falling) vSpeed += fallSpeed;
	else vSpeed = 0;
}
sf::Sprite PlayerChar::getSprite()
{
	return charSprite;
}