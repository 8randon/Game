#pragma once
#include "Character.h"

class Player:public Character
{
public:
	Player(int hp = 10, int str = 5, int mgc = 5, int x = 0, int y = 0, int h = 0, int w = 0) : Character(hp, str, x, y, h, w){
		cout << "Player" << endl;
	}

	//accessors
	int getxp() { return xp; }


	void levelup();


protected:
	int xp;
	int mgc;	//magic

private:
	string password;

};