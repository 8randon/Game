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
	wall * wpcur = lvs.getwall();
	spikes * spcur = lvs.gets();
	//sf::RectangleShape *wrcur = nullptr;
	//sf::RectangleShape *srcur = nullptr;

	bool collidew = false;
	bool collides = false;

	int i = 0;
	
	/*wall w1(lvs.getwall()->getx(), lvs.getwall()->gety(), lvs.getwall()->geth(), lvs.getwall()->getw()),
		w2(lvs.getwall()->getnext()->getx(), lvs.getwall()->getnext()->gety(), lvs.getwall()->getnext()->geth(), lvs.getwall()->getnext()->getw());
	spikes s1(lvs.gets()->getx(), lvs.gets()->gety(), lvs.gets()->geth(), lvs.gets()->getw()),
		s2(lvs.gets()->getnext()->getx(), lvs.gets()->getnext()->gety(), lvs.gets()->getnext()->geth(), lvs.gets()->getnext()->getw());*/

	vector<wall> wals;

	vector<spikes> spks;

	vector<sf::RectangleShape> wrects;

	vector<sf::RectangleShape> srects;

	//wrcur = wrects.data[0];
	//srcur = srects.data[0];

	while (wpcur)
	{
		wals.push_back(*wpcur);
		wpcur = wpcur->getnext();
	}

	while (spcur)
	{
		spks.push_back(*spcur);
		spcur = spcur->getnext();
	}


	for (i = 0; i < lvs.getnumw(); i++)
	{
		wrects.push_back(*(new sf::RectangleShape(sf::Vector2f (wals[i].getw(), wals[i].geth()))));
		wrects[i].setPosition(wals[i].getx(), wals[i].gety());
	}


	for (i = 0; i < lvs.getnums(); i++)
	{
		srects.push_back(*(new sf::RectangleShape(sf::Vector2f(spks[i].getw(), spks[i].geth()))));
		srects[i].setPosition(spks[i].getx(), spks[i].gety());
		/*srects.push_back(&spks.at[i]);
		srects.at[i]->setPosition(spks.at[i]->getx(), spks.at[i]->gety());*/
	}
	
	sf::Texture texture;
	sf::Sprite sprite;

	/*sf::RectangleShape wall1(sf::Vector2f (wals.at[0]->geth(), wals.at[0]->getw())), wall2(sf::Vector2f (wals.at[1]->geth(), wals.at[1]->getw())),
		spikes1(sf::Vector2f(spks.at[0]->geth(), spks.at[0]->getw())), spikes2(sf::Vector2f(spks.at[1]->geth(), spks.at[1]->getw()));*/

	/*wall1.setPosition(lvs.getwall()->getx(), lvs.getwall()->gety());
	wall2.setPosition(lvs.getwall()->getnext()->getx(), lvs.getwall()->getnext()->gety());

	spikes1.setPosition(lvs.gets()->getx(), lvs.gets()->gety());
	spikes2.setPosition(lvs.gets()->getnext()->getx(), lvs.gets()->getnext()->gety());*/

	sf::RenderWindow window;
	
	i = 0;
	int j = 0;
	int spot = 0;
	/*if (!texture.loadFromFile("images/SplashScreen.png"))
	{
	return;
	}*/
	window.create(sf::VideoMode(800, 600), "Samp");

	if (!texture.loadFromFile("sprites.png", sf::IntRect(0, 0, 22, 22)))
	{
		// error...
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 10, 10));

	window.draw(sprite);
	window.display();

	i = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				collides = false;
				collidew = false;

				if (event.key.code == sf::Keyboard::Left)
				{

					for (spot = 0; collidew == false && spot <  lvs.getnumw(); spot++) // checks walls until collision is true or there are no more walls to check
					{
						collidew = wals[spot].collision(p, i, j, 10, 10, 'L');
					}
					for (spot = 0; collides == false && spot < lvs.getnums(); spot++) // checks spikes until collision is true or there are no more spikes to check
					{
						collides = spks[spot].collision(p, i, j, 10, 10, 'L');
					}

					//if (!w1.collision(p, i, j, 10, 10, 'L') && !w2.collision(p, i, j, 10, 10, 'L') && !s1.collision(p, i, j, 10, 10, 'L') && !s2.collision(p, i, j, 10, 10, 'L'))
					if(collidew == false && collides == false) // if no collisions will occur, then character can move
					{
						sprite.setTextureRect(sf::IntRect(11, 0, 9, 9));
						i -= 10;
						//cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;

						sprite.move(-10, 0);
					}
				}

				if (event.key.code == sf::Keyboard::Right)
				{

					for (spot = 0; collidew == false && spot < lvs.getnumw(); spot++) // checks walls until collision is true or there are no more walls to check
					{
						collidew = wals[spot].collision(p, i, j, 10, 10, 'R');
					}
					for (spot = 0; collides == false && spot < lvs.getnums(); spot++) // checks spikes until collision is true or there are no more spikes to check
					{
						collides = spks[spot].collision(p, i, j, 10, 10, 'R');
					}

					//if (!w1.collision(p, i, j, 10, 10, 'R') && !w2.collision(p, i, j, 10, 10, 'R') && !s1.collision(p, i, j, 10, 10, 'R') && !s2.collision(p, i, j, 10, 10, 'R'))
					if (collidew == false && collides == false)
					{
						sprite.setTextureRect(sf::IntRect(11, 11, 9, 9));
						i += 10;
					//	cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(10, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					for (spot = 0; collidew == false && spot < lvs.getnumw(); spot++) // checks walls until collision is true or there are no more walls to check
					{
						collidew = wals[spot].collision(p, i, j, 10, 10, 'U');
					}
					for (spot = 0; collides == false && spot < lvs.getnums(); spot++) // checks spikes until collision is true or there are no more spikes to check
					{
						collides = spks[spot].collision(p, i, j, 10, 10, 'U');
					}

					//if (!w1.collision(p, i, j, 10, 10, 'U') && !w2.collision(p, i, j, 10, 10, 'U') && !s1.collision(p, i, j, 10, 10, 'U') && !s2.collision(p, i, j, 10, 10, 'U'))
					if (collidew == false && collides == false)
					{
						sprite.setTextureRect(sf::IntRect(0, 10, 9, 9));
						j -= 10;
						//cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, -10);
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					for (spot = 0; collidew == false && spot < lvs.getnumw(); spot++) // checks walls until collision is true or there are no more walls to check
					{
						collidew = wals[spot].collision(p, i, j, 10, 10, 'D');
					}
					for (spot = 0; collides == false && spot < lvs.getnums(); spot++) // checks spikes until collision is true or there are no more spikes to check
					{
						collides = spks[spot].collision(p, i, j, 10, 10, 'D');
					}

					//if (!w1.collision(p, i, j, 10, 10, 'D') && !w2.collision(p, i, j, 10, 10, 'D') && !s1.collision(p, i, j, 10, 10, 'D') && !s2.collision(p, i, j, 10, 10, 'D'))
					if (collidew == false && collides == false)
					{
						sprite.setTextureRect(sf::IntRect(0, 0, 9, 9));
						j += 10;
						//cout << i << endl << j << endl << w1.getx() << endl << w1.gety() << endl;
						sprite.move(0, 10);
					}
				}
			}
		}

		window.clear();
		window.draw(sprite);

		for (spot = 0; spot < lvs.getnumw(); spot++) 
		{
			window.draw(wrects[spot]);
		}
		spot = 0;
		for (spot = 0; spot < lvs.getnums(); spot++)
		{
			window.draw(srects[spot]);
		}

		/*window.draw(wall1);
		window.draw(wall2);
		window.draw(spikes1);
		window.draw(spikes2);*/
		window.display();
	}


}
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;