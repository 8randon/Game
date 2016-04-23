#include "InventoryItem_Hold.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Hold::InventoryItem_Hold(float new_durability, Hold_Buff_Type new_buff, float new_modifier, string new_name, string new_description) : InventoryItem(new_name, new_description)
{
	this->durability = new_durability;
	this->buff = new_buff;
}

InventoryItem_Hold::~InventoryItem_Hold()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

float InventoryItem_Hold::get_modifier() const
{
	return this->modifier;
}

// Public Member Functions -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//TODO write definition and add the reference to character once Character class is defined
void InventoryItem_Hold::equip(Character &character)
{
	switch(this->buff)
	{
	case ARMOR: 
		break;
	case ATTACK_DAMAGE:
		break;
	case HEALTH:
		break;
	}
}

//TODO write definition and add the reference to character once Character class is defined
void InventoryItem_Hold::dequip(Character &character)
{
}
