#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <vector>
#include "level.h"
#include <time.h>


using std::time_t;
using std::vector;


class Game
{

public:
	static void Start();

	//void setlv(level lv, int num) { lvs[num] = lv; }

	static void loaddata(level lv[], int i);

	static void runlv(level &lvs, Character *&p);

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};