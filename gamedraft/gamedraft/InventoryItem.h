#pragma once

#include "Item.h"


class InventoryItem : public Item
{
public:
	// Constructor/Destructor ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	InventoryItem(string new_name="\0");
	~InventoryItem();

private:
	string name;
};