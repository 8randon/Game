#include "stdfx.h"
#include "game.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
	_gameState = Game::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	Player p;
	sf::Event currentEvent;

	Character * pl = new Player();

	level levels[1] = {level(pl,"level1.txt")};

	while (_mainWindow.pollEvent(currentEvent))
	{

		switch (_gameState)
		{
		case Game::Playing:
		{
			_mainWindow.clear(sf::Color(255, 0, 0));
			_mainWindow.display();

			runlv1(levels[0], pl);

			if (currentEvent.type == sf::Event::Closed)
			{
				_gameState = Game::Exiting;
			}
			break;
		}
		}
	}
}

void Game::loaddata(level lv[], int i)
{
	lv[i].setinfo("level1.txt");
}


void Game::runlv1(level &lvs, Character *&p)
{
	
	wall w1(lvs.getwall()->getx(), lvs.getwall()->gety(), lvs.getwall()->geth(), lvs.getwall()->getw()),
		w2(lvs.getwall()->getnext()->getx(), lvs.getwall()->getnext()->gety(), lvs.getwall()->getnext()->geth(), lvs.getwall()->getnext()->getw());
	spikes s1(lvs.gets()->getx(), lvs.gets()->gety(), lvs.gets()->geth(), lvs.gets()->getw()),
		s2(lvs.gets()->getnext()->getx(), lvs.gets()->getnext()->gety(), lvs.gets()->getnext()->geth(), lvs.gets()->getnext()->getw());
	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape wall1(sf::Vector2f (lvs.getwall()->geth(), lvs.getwall()->getw())), wall2(sf::Vector2f (lvs.getwall()->getnext()->geth(), lvs.getwall()->getnext()->getw())),
		spikes1(sf::Vector2f(lvs.gets()->geth(), lvs.gets()->getw())), spikes2(sf::Vector2f(lvs.gets()->getnext()->geth(), lvs.gets()->getnext()->getw()));

	wall1.setPosition(lvs.getwall()->getx(), lvs.getwall()->gety());
	wall2.setPosition(lvs.getwall()->getnext()->getx(), lvs.getwall()->getnext()->gety());

	spikes1.setPosition(lvs.gets()->getx(), lvs.gets()->gety());
	spikes2.setPosition(lvs.gets()->getnext()->getx(), lvs.gets()->getnext()->gety());

	sf::RenderWindow window;
	
	int i = 0;
	int j = 0;
	/*if (!texture.loadFromFile("images/SplashScreen.png"))
	{
	return;
	}*/
	window.create(sf::VideoMode(800, 600), "Samp");

	if (!texture.loadFromFile("sprite.png", sf::IntRect(0, 0, 22, 22)))
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
					if (!w1.collision(p, i, j, 10, 10, 'L') && !w2.collision(p, i, j, 10, 10, 'L') && !s1.collision(p, i, j, 10, 10, 'L') && !s2.collision(p, i, j, 10, 10, 'L'))
					{
						i -= 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;

						sprite.move(-10, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					if (!w1.collision(p, i, j, 10, 10, 'R') && !w2.collision(p, i, j, 10, 10, 'R') && !s1.collision(p, i, j, 10, 10, 'R') && !s2.collision(p, i, j, 10, 10, 'R'))
					{
						i += 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(10, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (!w1.collision(p, i, j, 10, 10, 'U') && !w2.collision(p, i, j, 10, 10, 'U') && !s1.collision(p, i, j, 10, 10, 'U') && !s2.collision(p, i, j, 10, 10, 'U'))
					{
						j -= 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, -10);
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (!w1.collision(p, i, j, 10, 10, 'D') && !w2.collision(p, i, j, 10, 10, 'D') && !s1.collision(p, i, j, 10, 10, 'D') && !s2.collision(p, i, j, 10, 10, 'D'))
					{
						j += 10;
						cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, 10);
					}
				}
			}
		}

		window.clear();
		window.draw(sprite);
		window.draw(wall1);
		window.draw(wall2);
		window.draw(spikes1);
		window.draw(spikes1);
		window.display();
	}


}
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;