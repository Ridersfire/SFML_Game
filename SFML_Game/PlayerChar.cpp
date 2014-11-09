#include "PlayerChar.h"
#include "Platform.h"
#include <iostream>

PlayerChar::PlayerChar()
{
	charTexture.loadFromFile("Sprites//Green_Char.png");
	charSprite.setTexture(charTexture);
}

PlayerChar::PlayerChar(int charType)
{
	//loads 2 different sprites
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
	//updates the player, checks for user input, checks if he needs to fall,
	// then moves character around as needed
	getMovement();
	fall(platforms);
	yPos += vSpeed;
	xPos += hSpeed;
	std::cout << falling << std::endl;
	charSprite.setPosition(xPos, yPos);
}

void PlayerChar::getMovement()
{
	if (sf::Keyboard::isKeyPressed(KEY_MOVELEFT))
	{
		hSpeed = -5; //moves char left
	}
	else if (sf::Keyboard::isKeyPressed(KEY_MOVERIGHT))
	{
		hSpeed = 5; //moves char right 
	}
	else
	{
		hSpeed = 0; //makes char not move
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//Insert Skill here
	}
	if (sf::Keyboard::isKeyPressed(KEY_JUMP) && !falling)
	{
		//makes char jump if he needs to/can jump
		std::cout << "Jump" << std::endl;
		vSpeed = -jumpSpeed;
	}
}

void PlayerChar::fall(std::vector <Platform> platforms)
{
	falling = true;
	int platNum = platforms.size();
	for (int i = 0; i < platNum; i++)
	{
		Platform plat = platforms[i];
		float plat_yLoc = plat.getY();
		float plat_xLoc = plat.getX();
		int plat_yLen = 10; 
		int plat_xLen = plat.getWidth();

		/**
		--NOTE--
		Top Left - xPos,yPos
		Top Right - xPos+xLen
		Bottom Left - xPos, yPos+yLen
		Bottom Right - xPos + xLen, yPos + yLen
		*/



		// yPos + yLen is the bottom of the player
		// yPos + yLen + vSpeed is where the player will be
		// First checks to see if the player is above the platform
		// Second checks to see if the player will be below the platform

		if ((yPos + yLen <=  plat_yLoc && yPos + yLen + vSpeed >= plat_yLoc))
		{
			if (xPos + xLen > plat_xLoc && xPos < plat_xLoc + plat_xLen)
			{
				vSpeed = 0;
				yPos = plat_yLoc - yLen;
				falling = false;
			}
		}
		else if ((yPos > plat_yLoc + plat_yLen && yPos + vSpeed < plat_yLoc + plat_yLen))
		{
			vSpeed = 0;
			//yPos = plat_yLoc + plat_yLen;
		}
		//xPos + hSpeed < plat_xLoc + plat_xLen && xPos > plat_xLoc + plat_xLen && yPos + yLen <= plat_yLen + plat_yLoc && yPos + yLen > plat_yLoc
		// xPos is where the left side of the character is
		// xPos + hSpeed where the left side of the character will be
		/**
		 --Note--
		 this checks the bottom right of the character to see if the current platform could possibly
		 prevent the character from moving. This is checked by seeing if the platform exists between the
		 y position and the y+len position
		 first part checks to see if the top extends past the bottom
		*/
		else if (yPos + yLen > plat_yLoc && yPos < plat_yLoc+plat_yLen)
		{
			// Moving left collision detection
			if ((xPos >= plat_xLoc + plat_xLen && xPos + hSpeed <= plat_xLoc + plat_xLen))
			{
				hSpeed = 0;
				xPos = plat_xLoc + plat_xLen;
				
			} // Moving right collision detection
			else if (xPos + xLen <= plat_xLoc && xPos + xLen + hSpeed >= plat_xLoc)
			{
				hSpeed = 0;
				xPos = plat_xLoc - xLen;
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
//simply returns the character sprite
sf::Sprite PlayerChar::getSprite()
{
	return charSprite;
}