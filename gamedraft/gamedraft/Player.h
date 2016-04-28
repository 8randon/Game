#pragma once
#include "Character.h"
#include "InventoryItem_Consume.h"
#include "InventoryItem_Hold.h"
#include "KeyItem.h"
#include <math.h>

class Player:public Character
{
public:
	Player(int hp = 50, int str = 10, int armor=0, int x = 0, int y = 0, int h = 0, int w = 0) : Character(hp, hp, str, armor, x, y, h, w)
	{
		this->xp = 0;
		this->mgc = 0;

		// Add default items
		this->addInventory(new InventoryItem_Hold(2, 10,"Short Sword"));
		this->addInventory(new InventoryItem_Hold(1, 10, "Leather Armor"));

		cout << "Player" << endl;
	}

	Player(Player const &copy) {}

	~Player() {}

	//accessors
	int getxp() { return xp; }

	string loadInventory();
	string loadKeys();

	//mutators
	bool addInventory(InventoryItem *newItem);
	bool addKeyItem(KeyItem *newKey);

	void levelup();

	void attack(Character *&enemy);

protected:
	int xp;
	int mgc;	//magic add later

private:
	string password;
	InventoryItem *inventory[10];
	KeyItem *keypouch[5];
};