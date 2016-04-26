/*
	The class for all InventoryItems that can be consumed by the user to regernarate an attribute or grant a temporary buff. Once it is used, it is removed
	from the inventory.

	Written by Jensen Reitz
*/

#pragma once

#include "InventoryItem.h"


class InventoryItem_Consume : public InventoryItem
{
public:
	//- Defines the type of buff that the item holds
	typedef enum consume_buff_type
	{
		NONE, HEALTH
	} Consume_Buff_Type;


	InventoryItem_Consume(int new_modifier=0, int new_buff=0, char new_type_item='c', string new_name="\0", string new_description="\0");
	~InventoryItem_Consume();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	int get_modifier() const;
	int get_buff() const;

	// Public Member Functions ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	void consume(Character &character);

private:
	int modifier;
	Consume_Buff_Type buff;
};