#include "PlayerChar.h"

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
		charSprite.move(.1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		charSprite.move(-.1, 0);
	}
}

sf::Sprite PlayerChar::getSprite()
{
	return charSprite;
}