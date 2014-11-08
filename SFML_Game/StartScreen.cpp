#include "StartScreen.h"


StartScreen::StartScreen()
{
	//Sets up a set of rectangles used to hold the button coords
	sf::RectangleShape start_button, options_button, exit_button;
	start_button.setSize(sf::Vector2f(168.f, 48.f));
	options_button.setSize(sf::Vector2f(235.f, 48.f));
	exit_button.setSize(sf::Vector2f(121.f, 44.f));
	start_button.setPosition(sf::Vector2f(278.f, 258.f));
	options_button.setPosition(sf::Vector2f(243.f, 338.f));
	exit_button.setPosition(sf::Vector2f(302.f, 420.f));
	buttons.push_back(start_button);
	buttons.push_back(options_button);
	buttons.push_back(exit_button);
	backgroundImage.loadFromFile("startscreen\StartScreen.png");
	background.setTexture(&backgroundImage);
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(sf::Vector2f(0, 0));


}
/**
void StartScreen::render(sf::RenderWindow window)
{
	window.draw(background);

}
*/
StartScreen::~StartScreen()
{
}
