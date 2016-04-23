/*
	The base class for all items that can be found and stored in inventory within the game.

	Derives into:
	- InventoryItem
		The base class for all "items" that can be stored inside a character's inventory during the game
	- Key
		The item used to unlock doors within the dungeon.

	Written by Jensen Reitz
*/

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

protected:
	string name, description;
};
