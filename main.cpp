#include "SFML/Graphics.hpp"

#include "stdfx.h"
#include "game.h"
#include "obst.h"

using std::cout;
using std::endl;
//***************************
// FOR MOVEMENT: it should be taken that obtacles are of the same or greater widtch and height as the char
// NOTE: Make sprite dimention vars when you creat the class
//***************************

int main(void)
{
//	Game::Start();
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow window;
	int rectx = 100, recty = 100, rectw = 200, recth = 200;
	int i = 0;
	int j = 0;
	obst w1(50, 50, 200, 200), w2(20, 20, 30, 30);
	
	sf::RectangleShape w(sf::Vector2f(w1.getw(), w1.geth()));
	w.setPosition(w1.getx(), w1.gety());

	sf::RectangleShape o(sf::Vector2f(w2.getw(), w2.geth()));
	o.setPosition(w2.getx(), w2.gety());

	/*if (!texture.loadFromFile("images/SplashScreen.png"))
	{
		return;
	}*/

	sf::RectangleShape c(sf::Vector2f(rectw, recth));
	c.setPosition(rectx, recty);
	window.create(sf::VideoMode(800,600), "Samp");

	if (!texture.loadFromFile("sprites.png", sf::IntRect(0,0, 22, 22)))
	{
		// error...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 10, 10));

	window.draw(sprite);
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
					if (!w1.collision(i, j, 10, 10, 'L') && !w2.collision(i, j, 10, 10, 'L'))
					{
						i -= 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(-10, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					if (!w1.collision(i, j, 10, 10, 'R') && !w2.collision(i, j, 10, 10, 'R'))
					{
						i += 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(10, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (!w1.collision(i, j, 10, 10, 'U') && !w2.collision(i, j, 10, 10, 'U'))
					{
						j -= 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, -10);
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (!w1.collision(i, j, 10, 10, 'D') && !w2.collision(i, j, 10, 10, 'D'))
					{
						j += 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, 10);
					}
				}
				//	if ((((i - 10) > rectx && j > recty)) && (((i - 10) < rectx + rectw) && (j < recty + recth)))
				//	{
				//		cout << "x";
				//	}
				//	if (event.key.code == sf::Keyboard::Left)
				//	{
				//		sprite.setTextureRect(sf::IntRect(0, 0, 10, 10));
				//		if (i > 0 && !(((i - 10) > rectx && ((i - 10) < rectx + rectw)) && (((j + 10) > recty) && (((j + 10) < recty + recth) || (j) > recty) && ((j) < recty + recth))))
				//		{
				//			i -= 10;
				//			cout << i << endl << j << endl << rectx << endl << recty << endl;
				//			sprite.move(-10, 0);
				//		}
				//		//else { i = 0; }

				//	}
				//	if (event.key.code == sf::Keyboard::Right)
				//	{
				//		sprite.setTextureRect(sf::IntRect(11, 11, 10, 10));
				//		if (i + 10 < 400 && !(((i + 10 + 10) > rectx && ((i + 10 + 10) < rectx + rectw)) && ((((j + 10) > recty) && ((j + 10) < recty + recth) || (j) > recty) && ((j) < recty + recth))))
				//		{
				//			i += 10;
				//			sprite.move(10, 0);
				//			cout << i << endl << j << endl << rectx << endl << recty << endl;
				//		}
				//		//else { i = 400; }

				//	}

				//	if (event.key.code == sf::Keyboard::Down)
				//	{
				//		if (j < 200 && !(((i + 10 > rectx && (i + 10 < rectx + rectw)) || (i > rectx && (i < rectx + rectw))) && (((j + 10 + 10)>recty) && ((j + 10 + 10) < recty + recth))))
				//		{
				//			j += 10;
				//			sprite.move(0, 10);
				//			cout << i << endl << j << endl << rectx << endl << recty << endl;
				//		}
				//		//else { j = 200; }

				//	}
				//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				//	{
				//		if (j > 0 && !(((i + 10 > rectx && (i + 10 < rectx + rectw)) || (i > rectx && (i < rectx + rectw))) && (((j - 10)>recty) && ((j - 10) < recty + recth))))
				//		{
				//			j -= 10;
				//			sprite.move(0, -10);
				//			cout << i << endl << j << endl << rectx << endl << recty << endl;
				//		}
				//		//else { j = 0; }
				//	}
				}
			}
			window.clear();
			window.draw(sprite);
			//window.draw(c);
			window.draw(w);
			window.draw(o);
			window.display();
		}

	return 0;
}
