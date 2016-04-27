#include "InventoryItem_Consume.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Consume::InventoryItem_Consume(int new_modifier, int new_buff, char new_type_item, string new_name) : InventoryItem(new_type_item, new_name)
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

int InventoryItem_Consume::get_buff() const
{
	return (int)this->buff;
}

// Public Member Functions ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//- Applies the item's buff or regeneration to the character in possession's attribute
//- Accepts a reference to the character, passing the modified attribute values back through once the function call is complete
//NOTE: Does not destroy the object after modifying the character attributes. That must be done externally
//PRECONDITION: The character must have the attribute that will be modified as a member, this will not be checked within the function
void InventoryItem_Consume::consume(Character &character)
{
	switch(this->buff)
	{
	case HEALTH: character.set_hp(character.gethp()+(this->modifier));
		break;
	}
}
