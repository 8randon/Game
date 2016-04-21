#pragma once

#include "InventoryItem.h"


class InventoryItem_Hold : public InventoryItem
{
public:
	//Structs

	//- Defines the type of buff that the item holds
	typedef enum hold_buff_type
	{
		NONE, ARMOR, ATTACK_DAMAGE, HEALTH
	} Hold_Buff_Type;

	//Constructor/Destructor

	InventoryItem_Hold(float new_durability=0, Hold_Buff_Type new_buff=NONE, float new_modifier=0, string new_name="\0");
	InventoryItem_Hold();

private:
	float modifier, durability;
	Hold_Buff_Type buff;
};