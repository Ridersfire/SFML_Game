#include <SFML/Graphics.hpp>
#include "PlayerChar.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	PlayerChar playah(1);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(playah.getSprite());
		window.display();
		playah.move();

	}

	return 0;
}