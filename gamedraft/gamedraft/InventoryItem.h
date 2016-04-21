#pragma once

#include "Item.h"


class InventoryItem : public Item
{
public:
	// Constructor/Destructor ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	InventoryItem(string new_name="\0", string new_description="\0");
	~InventoryItem();

private:
};