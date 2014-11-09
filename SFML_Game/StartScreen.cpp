#include "StartScreen.h"
#include <iostream>

StartScreen::StartScreen()
{
	//Sets up a set of rectangles used to hold the button coords
	sf::RectangleShape start_button, options_button, exit_button;
	buttons["exit"] = Button("startscreen\\exitSprite.png", sf::Vector2f(302.f, 420.f));
	buttons["start"] = Button("StartScreen\\startSprite.png", sf::Vector2f(278.f, 258.f));
	mouseBounds_.height = 1.f;
	mouseBounds_.width = 1.f;
	//options_button.setSize(sf::Vector2f(235.f, 48.f));
	//options_button.setPosition(sf::Vector2f(243.f, 338.f));
	backgroundImage.loadFromFile("startscreen\\StartScreen.png");
	background.setTexture(&backgroundImage);
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(sf::Vector2f(0, 0));


}

void StartScreen::render(sf::RenderWindow & window)
{
	window.draw(background);

}

StartScreen::~StartScreen()
{
}

void StartScreen::handleInput(sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseBounds_.top = sf::Mouse::getPosition(window).y;
		mouseBounds_.left = sf::Mouse::getPosition(window).x;
		for (auto button : buttons)
		{
			if ((button.second).getBounds().intersects(mouseBounds_))
			{
				std::cout << "Clicked " << button.first << std::endl;
			}
		}
	}

}