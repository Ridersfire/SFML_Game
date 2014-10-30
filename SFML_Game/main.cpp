#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Sprite charSprite;
	sf::Texture charTexture;
	charTexture.loadFromFile("Sprites\\Char1.png");
	charSprite.setTexture(charTexture);
	sf::Sprite platform1;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(charSprite);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			charSprite.move(.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			charSprite.move(-.1, 0);
		}
	}

	return 0;
}