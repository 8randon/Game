#pragma once

#include <string>

using namespace std;


class Item
{
public:
	Item(string new_name="\0", string new_destription="\0");
	virtual ~Item();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	string get_name() const;
	string get_description() const;

private:
	string name, description;
};
