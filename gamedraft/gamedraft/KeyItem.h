/*
	The class for keys that are used for unlocking doors within the dungeon. It's only purpose is to hold a keyNumber that corresponds to a door's doorNumber.
	when the two the two match up, the door will open and the key is no longer relevant (Though keeping it until the end may eventually have some rewards,
	it's a work in progress).

	Written by Jensen Reitz
*/

#pragma once

#include "Item.h"


class KeyItem : public Item
{
public:
	KeyItem(int new_keyNumber=0, string new_name="\0", string new_description="\0");
	~KeyItem();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	int get_keyNumber() const;

private:
	int keyNumber;
};

