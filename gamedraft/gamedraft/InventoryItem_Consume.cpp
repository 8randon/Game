#include "InventoryItem_Consume.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Consume::InventoryItem_Consume(int new_modifier, Consume_Buff_Type new_buff, string new_name) : InventoryItem(new_name)
{
	this->modifier = new_modifier;
	this->buff = new_buff;
}

InventoryItem_Consume::~InventoryItem_Consume()
{
}

// Public Member Functions ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//TODO write definition once Character class is defined
void InventoryItem_Consume::use()
{
}
