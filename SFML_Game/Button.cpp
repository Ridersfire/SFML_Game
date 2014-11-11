#include "Button.h"
#include <string>

Button::Button()
{
}
Button::Button(std::string spriteName, sf::Vector2f position)
{
	texture_.loadFromFile(spriteName + ".png");
	canHover = texture_mouseOver.loadFromFile(spriteName + "_Hover.png");
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
/** 
Changes state of mouseOver if the mouse is over the button
*/
void Button::hoverOver(bool newState)
{
	mouseOver = newState;
}
/**
Returns the current sprite for the button
*/
sf::Sprite Button::getSprite()
{
	
	if (canHover && mouseOver)
	{
		sprite_.setTexture(texture_mouseOver);
	}
	else
	{
		sprite_.setTexture(texture_);
	}
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
Checks if the button is active
*/
bool Button::isActive()
{
	return enabled;
}
Button::~Button()
{
}
