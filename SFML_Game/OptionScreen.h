#pragma once
#include "Screen.h"
class OptionScreen : public Screen
{
public:
	OptionScreen();
	~OptionScreen();
	void render(sf::RenderWindow & window);
	void handleInput(sf::RenderWindow & window);

};

