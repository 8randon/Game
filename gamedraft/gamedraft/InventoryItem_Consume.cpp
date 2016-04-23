#include "InventoryItem_Consume.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Consume::InventoryItem_Consume(int new_modifier, Consume_Buff_Type new_buff, string new_name, string new_description) : InventoryItem(new_name, new_description)
{
	this->modifier = new_modifier;
	this->buff = new_buff;
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

//TODO write definition and add the reference to character once Character class is defined
void InventoryItem_Consume::consume()
{
}