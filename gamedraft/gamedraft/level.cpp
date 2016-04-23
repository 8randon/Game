#include "level.h"

level::level(Character * p, string filename)
{
	w = nullptr;
	s = nullptr;


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
		f >> junk;

		if (junk == 'w') // if wall object
		{
			if (getw() == nullptr)
			{
				setw(new wall());
				//wcur = w;
			}
			else
			{
			//	w->setnext(newwall());
			//	wcur = w->getnext();
			}

			f >> junk;
			f >> coor;
		//	wcur->setx(coor);
			f >> junk;
			f >> coor;
			//wcur->setx(coor);
			f >> junk;
			f >> coor;
			//wcur->setx(coor);
			f >> junk;
			f >> coor;
		//	wcur->setx(coor);
			f >> junk;
			f >> coor;
			f >> junk;

		}
		if (junk == 's') // if spikes object
		{
			if (getw() == nullptr)
			{
			//	sets(newspike());
				//scur = s;
			}
			else
			{
				//s->setnext(newspike());
			}
			/*f >> junk;
			f >> coor;
			scur->setx(coor);
			f >> junk;
			f >> coor;
			scur->setx(coor);
			f >> junk;
			f >> coor;
			scur->setx(coor);
			f >> junk;
			f >> coor;
			scur->setx(coor);
			f >> junk;
			f >> coor;
			f >> junk;*/
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
