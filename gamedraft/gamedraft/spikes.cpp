#include "spikes.h"

spikes::spikes(int ix, int iy, int iw, int ih, spikes * pnext) : obst(ix, iy, iw, ih)
{
	mpnext = pnext;
}


bool spikes::collision(Character *& player, int charx, int chary, int charw, int charh, char dir)
{
	if (dir == 'L')
	{
		if (charx > 0 && !(((charx - 9) >= getx() && ((charx - 9) <= getx() + getw())) && (((chary + 9)>gety()) && (((chary + 9) <= gety() + geth()) || (chary)>gety()) && ((chary) < gety() + geth()))))
		{

			return false;
		}
	}
	if (dir == 'R')
	{
		if (charx + 10 < 400 && !(((charx + charw + 9) >= getx() && ((charx + charw + 9) <= getx() + getw())) && ((((chary + 10) > gety()) && ((chary + 10) < gety() + geth()) || (chary) > gety()) && ((chary) < gety() + geth()))))
		{

			return false;
		}
	}

	if (dir == 'D')
	{
		if (chary < 400 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx >= x && (charx <= getx() + getw()))) && (((chary + charh + 10) > gety()) && ((chary + charh + 10) <= gety() + geth()))))
		{

			return false;
		}
	}
	if (dir == 'U')
	{
		if (chary > 0 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx >= getx() && (charx < getx() + getw()))) && (((chary - 10) > gety()) && ((chary - 10) < gety() + geth()))))
			//if (chary > 0 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx > getx() && (charx < getx() + getw()))) && (((chary - 10)>gety()) && ((chary - 10) < gety() + geth()))))
		{

			return false;
		}
	}

	
	
	
	
	
	
	/*
	if (dir == 'L')
	{
		if (charx > 0 && !(((charx - 10) > getx() && ((charx - 10) < getx() + getw())) && (((chary + 10)>gety()) && (((chary + 10) < gety() + geth()) || (chary)>gety()) && ((chary) < gety() + geth()))))
		{
			
			return false;
		}
	}
	if (dir == 'R')
	{
		if (charx + 10 < 400 && !(((charx + charw + 10) > getx() && ((charx + charw + 10) < getx() + getw())) && ((((chary + 10) > gety()) && ((chary + 10) < gety() + geth()) || (chary) > gety()) && ((chary) < gety() + h))))
		{
			
			return false;
		}
	}

	if (dir == 'D')
	{
		if (chary < 200 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx > x && (charx < getx() + getw()))) && (((chary + charh + 10)>gety()) && ((chary + charh + 10) < gety() + geth()))))
		{
			
			return false;
		}
	}
	if (dir == 'U')
	{
		if (chary > 0 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx > getx() && (charx < getx() + getw()))) && (((chary - 10)>gety()) && ((chary - 10) < gety() + geth()))))
		{
			
			return false;
		}
	}
*/
	cout << 's';

	return true;
}