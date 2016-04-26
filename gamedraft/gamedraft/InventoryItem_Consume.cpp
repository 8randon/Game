#include "InventoryItem_Consume.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Consume::InventoryItem_Consume(int new_modifier, int new_buff, string new_name, string new_description) : InventoryItem(new_name, new_description)
{
	this->modifier = new_modifier;
	this->buff = (Consume_Buff_Type)new_buff;
}

InventoryItem_Consume::~InventoryItem_Consume()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int InventoryItem_Consume::get_modifier() const
{
	return this->modifier;
}

// Public Member Functions ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void InventoryItem_Consume::consume(Character &character)
{
	switch(this->buff)
	{
	case HEALTH: character.set_hp(character.gethp()+(this->modifier));
		break;
	}
}
