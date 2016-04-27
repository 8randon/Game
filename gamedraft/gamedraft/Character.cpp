#include "Character.h"

Character::Character(int mhp, int hp, int str,int armor, int x, int y, int h, int w)
{
	cout << "Character Constructor" << endl;
}

//TODO Write copy constructor
Character::Character(Character & copy)
{
}

Character::~Character()
{
	cout << "Character Destructor" << endl;
}

//member functions
bool Character::canMove(int temp)
{
	//check if obstacle is in way based on temp value for direction
	if (temp == 1)
		//y++
		//if there is an obstacle return false
			return false;
	else if (temp == 2)
		//y--
		//if obstacle
			return false;
	else if (temp == 3)
		//x--
		//if obstacle
			return false;
	else if (temp == 4)
		//x++
		//if obstacle
			return false;
}
void Character::moveUp()
{
	if (canMove(1))
		y++;
}
void Character::moveDown()
{
	if (canMove(2))
		y--;
}
void Character::moveLeft()
{
	if (canMove(3))
		x--;
}
void Character::moveRight()
{
	if (canMove(4))
		x++;
}

void Character::attack(Character *&enemy)
{
	if (distance(enemy))
	{
		enemy->hp -= this->str;
	}
}

bool Character::distance(Character *&enemy)
{
	int dis = 0;
	double a = 0;	//hold y values
	double b = 0;	//hold x values
	a = y - enemy->getypos();
	b = x - enemy->getxpos();
	a = a*a;
	b = b*b;
	dis = sqrt(a + b);

	if (dis <= 10) {
		return true;
	}
	else return false;
}
