#pragma once

#include "InventoryItem.h"


// Structs *********************************************************************************************************************************************************************************************

//- Defines the type of buff that the item holds
typedef enum hold_buff_type
{
	NONE, ARMOR, ATTACK_DAMAGE, HEALTH
} Hold_Buff_Type;


class InventoryItem_Hold : public InventoryItem
{
public:
	InventoryItem_Hold(float new_durability=0, Hold_Buff_Type new_buff=NONE, float new_modifier=0, string new_name="\0", string new_description="\0");
	~InventoryItem_Hold();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	float get_modifier() const;
	Hold_Buff_Type get_buff() const;

	// Public Member Functions -------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	void equip(); //TODO add reference to character once the class has been created
	void dequip(); //TODO add reference to character once the class has been created

private:
	float modifier, durability;
	Hold_Buff_Type buff;
};