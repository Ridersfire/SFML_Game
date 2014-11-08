#pragma once
#include <SFML/Graphics.hpp>
class Platform;

class PlayerChar
{
public:
	PlayerChar();
	PlayerChar(int charType);
	~PlayerChar();
	void update(std::vector <Platform>);
	void getMovement();
	void fall(std::vector <Platform>);
	sf::Sprite getSprite();
private:
	float xPos = 0;
	float yPos = 0;
	int yLen = 32;
	int xLen = 16;
	double vSpeed = 0;
	double hSpeed = 0;
	double fallSpeed = .5;
	float jumpSpeed = 20;
	bool falling = true;
	sf::Sprite charSprite;
	sf::Texture charTexture;
	/**
	const int TOPLEFT = 0;
	const int TOPRIGHT = 1;
	const int BOTTOMRIGHT = 2;
	const int BOTTOMLEFT = 3;
	*/
	sf::Keyboard::Key KEY_MOVERIGHT = sf::Keyboard::D;
	sf::Keyboard::Key KEY_MOVELEFT = sf::Keyboard::A;
	sf::Keyboard::Key KEY_JUMP = sf::Keyboard::Space;
	

	
};

