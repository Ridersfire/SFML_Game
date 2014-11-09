#include "Button.h"


Button::Button()
{
}
Button::Button(std::string spriteName, sf::Vector2f position)
{
	texture_.loadFromFile(spriteName);
	sprite_.setTexture(texture_);
	sprite_.setPosition(position);

}
sf::FloatRect Button::getBounds()
{
	return sprite_.getGlobalBounds();
}
Button::~Button()
{
}
