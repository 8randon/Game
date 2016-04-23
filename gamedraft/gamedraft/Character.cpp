#include "Character.h"

Character::Character(int hp, int str,int armor, int x, int y, int h, int w)
{
	cout << "Character Constructor" << endl;
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
	if (enemy)
	{
		enemy->hp -= this->str;
	}
}