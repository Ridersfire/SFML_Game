#pragma once
#include <SFML/Graphics.hpp>
class Platform;

class PlayerChar
{
public:
	PlayerChar(int charType);
	~PlayerChar();
	void move();
	void fall(std::vector <Platform>);
	sf::Sprite getSprite();
private:
	float xPos = 0;
	float yPos = 0;
	int yLen = 32;
	int xLen = 16;
	double vSpeed = 0;
	bool falling = true;
	sf::Sprite charSprite;
	sf::Texture charTexture;
	
};

