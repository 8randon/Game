#pragma once
#include "Character.h"

class Monster:public Character
{
public:
	//starting enemy (level 1 and >)
	//med health, low attack
	Monster(int mhp = 10, int hp = 10, int str = 2) : Character(mhp, hp, str) {
		cout << "Monster" << endl;
		cout << hp << endl;
		cout << str << endl;
	};
	int height;
	int width;
};

class Ghoul :public Character
{
public: 
	//starting enemy (level 1 and >)
	//low health, med attack
	Ghoul(int mhp = 3, int hp = 3, int str = 5) : Character(mhp, hp, str) {
		cout << "Ghoul" << endl;
		cout << hp << endl;
		cout << str << endl;
	}
};

class Zombie :public Character
{
public:
	//enemy (around level 2 and >)
	//med health, med attack
	Zombie(int mhp = 10, int hp = 10, int str = 5) : Character(mhp, hp, str) {
		cout << "Zombie" << endl;
		cout << hp << endl;
		cout << str << endl;
	}
};