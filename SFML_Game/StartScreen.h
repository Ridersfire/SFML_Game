#pragma once

#include <SFML\Graphics.hpp>
#include "Screen.h"

class StartScreen : public Screen
{
public:
	StartScreen();
	~StartScreen();
	void render(sf::RenderWindow & window);
	void handleInput();

	std::vector <sf::RectangleShape> buttons;
};

