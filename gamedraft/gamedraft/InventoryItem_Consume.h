#pragma once

#include "InventoryItem.h"


class InventoryItem_Consume : public InventoryItem
{
public:
	// Structs --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//- Defines the type of buff that the item holds
	typedef enum consume_buff_type
	{
		NONE, HEALTH
	} Consume_Buff_Type;

	// Constructor/Destructor -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	InventoryItem_Consume(int new_modifier=0, Consume_Buff_Type new_buff=NONE, string new_name="\0");
	~InventoryItem_Consume();

	// Public Member Functions ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	void use(); //TODO Add a reference to the character class once it is created

private:
	int modifier;
	Consume_Buff_Type buff;
};