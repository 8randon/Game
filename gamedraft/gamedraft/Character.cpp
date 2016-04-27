#include "Character.h"

Character::Character(int mhp, int hp, int str, int armor, int x, int y, int h, int w)
{
	cout << "Character Constructor" << endl;
}

Character::~Character()
{
	cout << "Character Destructor" << endl;
}

////member functions
//bool Character::canMove(int temp)
//{
//	//check if obstacle is in way based on temp value for direction
//	if (temp == 1)
//		//y++
//		//if there is an obstacle return false
//			return false;
//	else if (temp == 2)
//		//y--
//		//if obstacle
//			return false;
//	else if (temp == 3)
//		//x--
//		//if obstacle
//			return false;
//	else if (temp == 4)
//		//x++
//		//if obstacle
//			return false;
//}
//void Character::moveUp()
//{
//	if (canMove(1))
//		y++;
//}
//void Character::moveDown()
//{
//	if (canMove(2))
//		y--;
//}
//void Character::moveLeft()
//{
//	if (canMove(3))
//		x--;
//}
//void Character::moveRight()
//{
//	if (canMove(4))
//		x++;
//}

void Character::automove(Character *&player)
{
	int temp = 0;
	//enemy reference is the player
	if (isDistance(distance(player)))
	{
		while (distance(player))
		{
			if (player->getxpos() < this->x)
				x--;
			if (player->getxpos() > this->x)
				x++;
			if (player->getypos() < this->y)
				y--;
			if (player->getypos() > this->y)
				y++;
		}
	}

}

void Character::attack(Character *&enemy)
{
	int dmg = 0;
	if (distance(enemy))	//isdistance
	{
		while (enemy->gethp() != 0)
			dmg = armor - enemy->getstr();
		enemy->set_hp(enemy->gethp() - dmg);
	}
}

int Character::distance(Character *&player)
{
	int dis = 0;
	double a = 0;	//hold y values
	double b = 0;	//hold x values
	a = y - player->getypos();
	b = x - player->getxpos();
	a = a*a;
	b = b*b;
	dis = (int)sqrt(a + b);

	return dis;
}

bool Character::isDistance(int temp)
{
	if (temp <= 20)
		return true;
	else return false;
}