#pragma once

#include "Screen.h"
#include "Game.h"

class OptionScreen : public Screen
{
public:
	OptionScreen();
	~OptionScreen();
	void render(Game * game);
	void handleInput(Game * game);

};

