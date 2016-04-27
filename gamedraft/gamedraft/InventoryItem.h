/*
	The base class for all items that are stored within a character's inventory. Provides a base-case to support polymorphic behavior throughout the
	array that is the inventory, allowing both classes that are derived from this to preside within dynamically.

	Derives into:
	- InventoryItem_Hold
		The class for all InventoryItems that can be "held" and/or equipped, adding an attribute buff to the character holding them
	- InventoryItem_Consume
		The class for all InventoryItems that are consumed to regenerate health or other attributes that may be low

	Written by Jensen Reitz
*/

#pragma once

#include "Item.h"
#include "Character.h"

class InventoryItem : public Item
{
public:
	InventoryItem(char new_type_item='\0', string new_name="\0");
	virtual ~InventoryItem();

	//Accessors

	char get_type_item() const;

protected:
	char type_item; //h='h' for holdable, 'c' for consumable
};