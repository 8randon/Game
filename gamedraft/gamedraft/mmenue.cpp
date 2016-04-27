#include "mmenue.h"

bool MainMenu::Show(sf::RenderWindow& window)
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i localPosition;

	if (!texture.loadFromFile("images/SplashScreen.png"))
	{
		return false;
	}

	sprite.setTexture(texture);

	window.draw(sprite);
	window.display();

	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::EventType::MouseButtonPressed)
			{
				localPosition = sf::Mouse::getPosition(window);
				




			}
		}
	}
	return true;
}