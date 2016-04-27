//Brandon T.
#pragma once
#include "Player.h"
#include "spikes.h"
#include "Enemy.h"
#include <fstream>
#include <vector>

using std::fstream;
using std::cin;
using std::cout;
using std::vector;

class level
{
public:
	level(string filename);
	~level() { return; }

	void setinfo(string filename);

	wall * newwall() { wall * pmem = new wall(); return pmem; }
	spikes * newspike() { spikes * pmem = new spikes(); return pmem;}
	wall * getwall() { return w; }
	spikes * gets() { return s; }

	int getnumw() { return numwalls; }
	int getnums() { return numspikes; }
	int getnummonsters() { return nummstrs; }
	Monster &getmonster(int i) { return this->m[i]; }
	//void runlv();


	void addnumw(int newalls) { numwalls += newalls; }
	void addnums(int newspikes) { numspikes += newspikes; }
	void addnummnstrs(int newm) { nummstrs += newm; }

	void setw(wall * nw);
	void sets(spikes * ns);

private:
	int numwalls;
	int numspikes;
	int nummstrs;
	wall * w;
	spikes * s;
	vector<Monster> m;
};

