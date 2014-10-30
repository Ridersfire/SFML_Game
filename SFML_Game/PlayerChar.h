#pragma once
#include <SFML/Graphics.hpp>

class PlayerChar
{
public:
	PlayerChar(int charType);
	~PlayerChar();
	void move();
	sf::Sprite getSprite();
private:
	float xPos;
	float yPos;
	sf::Sprite charSprite;
	sf::Texture charTexture;
	
};

