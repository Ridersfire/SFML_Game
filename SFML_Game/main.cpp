#include <SFML/Graphics.hpp>
#include "PlayerChar.h"
#include "Platform.h"
#include "Level.h"
#include <vector>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	PlayerChar playah(6);
	std::vector < Platform > platforms;
	sf::Image testImage;
	testImage.loadFromFile("Levels\\level1.png");

	Level testLevel(testImage);

	/**
	Platform platforms[2];
	platforms[0] = Platform(0,300);
	platforms[1] = Platform(400, 400);
	*/
	platforms = testLevel.platforms;
	
	sf::Clock clock;
	float lastTime = 0;
	window.setFramerateLimit(20);
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
		playah.update(platforms);	
		window.draw(playah.getSprite());
		window.display();
		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / (currentTime);
		lastTime = currentTime;
		std::cout << fps << std::endl;
		

	}

	return 0;
}