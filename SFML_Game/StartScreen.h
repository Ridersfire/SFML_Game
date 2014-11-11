#pragma once

#include "Screen.h"

class StartScreen : public Screen
{
public:
	StartScreen();
	~StartScreen();
	void render(Game * game);
	void handleInput(Game * game);
	sf::FloatRect mouseBounds_;
	std::map <std::string, Button*> buttons;
};

