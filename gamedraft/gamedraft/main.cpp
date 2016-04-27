#include "SFML/Graphics.hpp"

#include "stdfx.h"
#include "game.h"

int main(void)
{
	Game::Start();
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape c(sf::Vector2f(10, 10));
	sf::RenderWindow window;
	int i = 0;
	int j = 0;
	/*if (!texture.loadFromFile("images/SplashScreen.png"))
	{
		return;
	}*/
	window.create(sf::VideoMode(800,600), "Samp");

	sprite.setTexture(texture);

	window.draw(c);
	window.display();

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					if (i > 0)
					{
						i--;
						c.move(-1, 0);
					}
					else { i = 0; }

				}
				if (event.key.code == sf::Keyboard::Right)
				{
					if (i < 200)
					{
						i++;
						c.move(1, 0);
					}
					else { i = 200; }

				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (j < 200)
					{
						j++;
						c.move(0, 1);
					}
					else { j = 200; }

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (j > 0)
					{
						j--;
						c.move(0, -1);
					}
					else { j = 0; }
				}
			}
		}

		window.clear();
		window.draw(c);
		window.display();
	}

	return 0;
}
