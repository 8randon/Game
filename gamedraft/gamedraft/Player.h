#pragma once
#include "Character.h"
#include "InventoryItem_Consume.h"
#include "InventoryItem_Hold.h"
#include "KeyItem.h"

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
	InventoryItem inventory[10];
	KeyItem keypouch[5];
};