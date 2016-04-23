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
	Character(int mhp = 0, int hp = 0, int str = 0, int armor=0, int x = 0, int y = 0, int h = 0, int w = 0);

	//destructor
	~Character();

	//accessors
	int gethp() { return hp; }
	int getstr() { return str; }
	int getarmor() { return armor; }
	int getxpos() { return x; }
	int getypos() { return y; }

	// Mutators - Added by Jensen Reitz
	void set_hp(const int new_hp) { this->hp = new_hp; }
	void set_str(const int new_str) { this->str = new_str; }
	void set_armor(const int new_armor) { this->armor = new_armor; }

	//member functions
	virtual bool canMove(int temp);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	virtual void attack(Character *&enemy);


protected:
	int mhp;	//max health
	int hp; 
	int str;
	int armor;

	int x;
	int y;
	int h;
	int w;
};