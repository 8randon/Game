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

