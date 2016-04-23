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

	InventoryItem_Hold(float new_durability=0, Hold_Buff_Type new_buff=NONE, float new_modifier=0, string new_name="\0", string new_description="\0");
	~InventoryItem_Hold();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	float get_modifier() const;

	// Public Member Functions -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//TODO write definition and add the reference to character once Character class is defined
	//- Assigns attribute buffs to the character "holding" the item
	//- Accepts a reference to the Character, passing the modified values back through once the function call is complete
	//PRECONDITION: The character must have the attribute that will be modified as a member, this will not be checked within the function
	void equip();

	//TODO write definition and add the reference to character once Character class is defined
	//- Takes away the attribute buffs that would be assigned when the item was equipped
	//- Accepts a reference to the Character, passing the modified values back through once the function call is complete
	//PRECONDITION: The character must have the attribute that will be modified as a member, this will not be checked within the function
	void dequip(); //TODO add reference to character once the class has been created

private:
	float modifier, durability;
	Hold_Buff_Type buff;
};