#pragma once
#include <SFML\Graphics.hpp>
class Screen
{
public:
	Screen();
	sf::RectangleShape background;
	sf::Texture backgroundImage;
	~Screen();
	virtual void render(sf::RenderWindow & window) = 0;
	virtual void handleInput(sf::RenderWindow & window) = 0;

};

