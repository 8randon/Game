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
	Character(int hp = 0, int str = 0, int x = 0, int y = 0, int h = 0, int w = 0);

	//destructor
	~Character();

	//accessors
	int gethp() { return hp; }
	int getstr() { return str; }
	int getxpos() { return x; }
	int getypos() { return y; }

	//member functions
	virtual bool canMove(int temp);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	virtual void attack(Character *&enemy);


protected:
	int hp; 
	int str;

	int x;
	int y;
	int h = 20;
	int w = 20;
};