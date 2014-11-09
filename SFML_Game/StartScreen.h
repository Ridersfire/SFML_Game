#pragma once

#include <SFML\Graphics.hpp>
#include "SFML\Graphics\Rect.hpp"
#include "Button.h"
#include "Screen.h"

class StartScreen : public Screen
{
public:
	StartScreen();
	~StartScreen();
	void render(sf::RenderWindow & window);
	void handleInput(sf::RenderWindow & window);
	sf::FloatRect mouseBounds_;
	std::map <std::string, Button> buttons;
};

