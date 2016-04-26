/*
	The class for all InventoryItems that can be held and equipped by a character. They add a buff to the character's attributes, scaling health, damage,
	or armor. The buff disapears once the item is "dequipped" - removed from the inventory.

	Written by Jensen Reitz
*/

#pragma once

#include "InventoryItem.h"


class InventoryItem_Hold : public InventoryItem
{
public:
	//- Defines the type of buff that the item holds
	typedef enum hold_buff_type
	{
		NONE, ARMOR, ATTACK_DAMAGE, HEALTH
	} Hold_Buff_Type;

	InventoryItem_Hold(int new_buff=0, int new_modifier=0, char new_type_item='h', string new_name="\0", string new_description="\0");
	~InventoryItem_Hold();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	int get_modifier() const;
	int get_buff() const;

	// Public Member Functions -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	void equip(Character &character);
	void dequip(Character &character);

private:
	int modifier;
	Hold_Buff_Type buff;
};