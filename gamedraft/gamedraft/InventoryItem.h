#pragma once

#include "Item.h"


class InventoryItem : public Item
{
public:
	InventoryItem(string new_name="\0", string new_description="\0");
	virtual ~InventoryItem();

private:
};