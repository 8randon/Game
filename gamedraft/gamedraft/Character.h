#pragma once
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Character
{
public:
	//constructor
	Character(int mmmhp = 0, int mmhp = 0, int mstr = 0, int marmor=0, int mx = 0, int my = 0, int mh = 0, int mw = 0);

	//destructor
	virtual ~Character();

	//accessors
	int getmhp() { return this->mhp; } //Added by Jensen Reitz but mostly Alex George
	int gethp() { return hp; }
	int getstr() { return str; }
	int getarmor() { return armor; }
	int getxpos() { return x; }
	int getypos() { return y; }

	bool checkdead() 
	{ 
		if (this->hp <= 0) 
			this->isDead = true; 
	
		return this->isDead; 
	}

	// Mutators - Added by Jensen Reitz
	void set_mhp(const int new_mhp) { this->mhp = new_mhp; }
	void set_hp(const int new_hp) { this->hp = new_hp; }
	void set_str(const int new_str) { this->str = new_str; }
	void set_armor(const int new_armor) { this->armor = new_armor; }
	void setpos(const int newx, const int newy) { this->x = newx; this->y = newy; }

	//member functions
	//virtual bool canMove(int temp);
	//void moveUp();
	//void moveDown();
	//void moveLeft();
	//void moveRight();

	virtual void attack(Character &enemy);

	int distance(Character &enemy);

	bool isDistance(int temp);

	bool isDistance_attack(int temp);

	void automove(Character *&enemy);

protected:
	int mhp;	//max health
	int hp; 
	int str;
	int armor;
	
	bool isDead;

	int x;
	int y;
	int h;
	int w;
};