#include "Button.h"
#include <string>

Button::Button()
{
}
Button::Button(std::string spriteName, sf::Vector2f position)
{
	texture_.loadFromFile(spriteName + ".png");
	//checks to see if the texture was loaded
	sprite_.setTexture(texture_);
	sprite_.setPosition(position);
}
/** 
returns a floating rectange with Button's boundary
*/
sf::FloatRect Button::getBounds()
{
	//sprite_.setTexture(texture_);
	return sprite_.getGlobalBounds();
}

void Button::centerOnWindow()
{
	int newXPos = (800)/2-(sprite_.getGlobalBounds().width)/2;
	int yPos = sprite_.getPosition().y;
	sprite_.setPosition(sf::Vector2f(newXPos, yPos));
}
/** 
Changes state of mouseOver if the mouse is over the button
*/
void Button::hoverOver(bool newState)
{
	mouseOver = newState;
}
/**
Returns the current sprite for the button
Changes the color to grey if mouse is overtop the button
*/
sf::Sprite Button::getSprite()
{
	if (mouseOver)
		sprite_.setColor(sf::Color(200, 200, 200));
	else
		sprite_.setColor(sf::Color::White);
	return sprite_;
}
/**
Changes whether or not the button is active
*/
void Button::toggleActive()
{
	enabled = !enabled;
}
/**
returns if the button is active
*/
bool Button::isActive()
{
	return enabled;
}
Button::~Button()
{
}
