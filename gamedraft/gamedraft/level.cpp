#include "level.h"

level::level(Character * p, string filename)
{
	w = nullptr;
	s = nullptr;
	numwalls = 0;
	numspikes = 0;

	setinfo(filename);
}




void level::setinfo(string filename)
{
	fstream f(filename);
	spikes *scur = s;
	wall *wcur = w;
	int coor = 0;

	char junk = '\0';

	while (!f.eof())
	{
		junk = '\0';

		f >> junk;

		if (junk == 'w') // if wall object
		{
			if (getwall() == nullptr)
			{
				setw(new wall());
				wcur = w;
				addnumw(1);
			}
			else
			{
				wcur->setnext(new wall());
				wcur = wcur->getnext();
				addnumw(1);
			}

			f >> junk;
			f >> coor;
			wcur->setx(coor);
			f >> junk;
			f >> coor;
			wcur->sety(coor);
			f >> junk;
			f >> coor;
			wcur->seth(coor);
			f >> junk;
			f >> coor;
			wcur->setw(coor);

		}
		else if (junk == 's') // if spikes object
		{
			if (gets() == nullptr)
			{
				sets(newspike());
				scur = s;
				addnums(1);
			}
			else
			{
				scur->setnext(newspike());
				scur = scur->getnext();
				addnums(1);
			}
			f >> junk;
			f >> coor;
			scur->setx(coor);
			f >> junk;
			f >> coor;
			scur->sety(coor);
			f >> junk;
			f >> coor;
			scur->seth(coor);
			f >> junk;
			f >> coor;
			scur->setw(coor);
		}
		

	}

}

void level::setw(wall * nw)
{
	this->w = nw;
}

void level::sets(spikes * ns)
{
	this->s = ns;
}


void runlv(Player *& player)
{

}