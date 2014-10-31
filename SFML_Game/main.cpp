#include <SFML/Graphics.hpp>
#include "PlayerChar.h"
#include "Platform.h"
#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	PlayerChar playah(1);
	std::vector < Platform > platforms;
	/**
	Platform platforms[2];
	platforms[0] = Platform(0,300);
	platforms[1] = Platform(400, 400);
	*/
	platforms.push_back(Platform(0, 300));
	platforms.push_back(Platform(400, 400));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (Platform plat : platforms)
		{
			window.draw(plat.getShape());
		}
		playah.fall(platforms);
		playah.move();
		window.draw(playah.getSprite());
		window.display();
		

	}

	return 0;
}