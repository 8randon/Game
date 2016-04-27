//Brandon T.
#pragma once
#include "Player.h"
#include "spikes.h"

#include <fstream>

using std::fstream;
using std::cin;
using std::cout;

class level
{
public:
	level(Character * pstring, string filename);
	~level() { return; }

	void setinfo(string filename);

	wall * newwall() { wall * pmem = new wall(); return pmem; }
	spikes * newspike() { spikes * pmem = new spikes(); return pmem;}
	wall * getwall() { return w; }
	spikes * gets() { return s; }

	int getnumw() { return numwalls; }
	int getnums() { return numspikes; }

	//void runlv();


	void addnumw(int newalls) { numwalls += newalls; }
	void addnums(int newspikes) { numspikes += newspikes; }

	void setw(wall * nw);
	void sets(spikes * ns);

private:
	int numwalls;
	int numspikes;
	wall * w;
	spikes * s;
};

