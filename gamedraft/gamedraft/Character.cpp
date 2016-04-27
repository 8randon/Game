#include "Character.h"

Character::Character(int mmmhp, int mmhp, int mstr, int marmor, int mx, int my, int mh, int mw)
{
	mhp = mmmhp;
	hp = mmhp;
	str = mstr;
	armor = marmor;
	x = mx;
	y = my;
	h = mh;
	w = mw;

	isDead = false;

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
	if (isDistance(distance(*player)))
	{
			cout << "following" << endl;
			if (player->getxpos() <= this->x)
				this->x-=10;
			if (player->getxpos() >= this->x)
				this->x+=10;
			if (player->getypos() <= this->y)
				this->y-=10;
			if (player->getypos() >= this->y)
				this->y+=10;

			//this->setpos(x, y);
	}
}


void Character::attack(Character &enemy)
{
	
	int dmg = 0;
	if (isDistance_attack(distance(enemy)))
	{
		cout << "attacking" << endl;
		enemy.set_hp(enemy.gethp() - this->str);
	}
}

int Character::distance(Character &player)
{
	int dis = 0;
	double a = 0;	//hold y values
	double b = 0;	//hold x values
	a = y - player.getypos();
	b = x - player.getxpos();
	a = a*a;
	b = b*b;
	dis = (int)sqrt(a + b);

	return dis;
}

bool Character::isDistance(int temp)
{
	if (temp <= 1000)
	{
		return true;
	}
		
	else
	{
		return false;
	}
		
}

bool Character::isDistance_attack(int temp)
{
	if (temp <= 10)
	{
		return true;
	}

	else
	{
		return false;
	}

}