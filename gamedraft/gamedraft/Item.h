#pragma once

#include <string>

using namespace std;


class Item
{
public:
	// Constructor/Destructor ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	Item(string new_name="\0", string new_destription="\0");
	~Item();

private:
	string name, description;
};
