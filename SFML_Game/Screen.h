#pragma once

#include <SFML\Graphics.hpp>
#include "Button.h"
class Game;

class Screen
{
public:
	Screen();
	sf::RectangleShape background;
	sf::Texture backgroundImage;
	~Screen();
	virtual void render(Game * game) = 0;
	virtual void handleInput(Game * game) = 0;

};

