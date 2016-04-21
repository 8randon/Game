#include "InventoryItem_Hold.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Hold::InventoryItem_Hold(float new_durability, Hold_Buff_Type new_buff, float new_modifier, string new_name, string new_description) : InventoryItem(new_name, new_description)
{
	this->durability = new_durability;
	this->buff = new_buff;
}

InventoryItem_Hold::InventoryItem_Hold()
{
}
