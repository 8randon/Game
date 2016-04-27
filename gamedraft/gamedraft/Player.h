#pragma once
#include "Character.h"
#include "InventoryItem_Consume.h"
#include "InventoryItem_Hold.h"
#include "KeyItem.h"

class Player:public Character
{
public:
	Player(int hp = 10, int str = 5, int armor=0, int x = 0, int y = 0, int h = 0, int w = 0) : Character(hp, hp, str, armor, x, y, h, w){
		cout << "Player" << endl;
	}

	Player(Player const &copy) {}

	~Player() {}

	//accessors
	int getxp() { return xp; }

	string loadInventory(); //Added by Jensen Reitz
	string loadKeys(); //

	//mutators
	void addInventory(InventoryItem newItem);
	void addKeyItem(KeyItem newKey);

	void levelup();


protected:
	int xp;
	int mgc;	//magic add later

private:
	string password;
	InventoryItem inventory[10];
	KeyItem keypouch[5];
};