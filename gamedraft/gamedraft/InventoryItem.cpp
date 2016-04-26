#include "InventoryItem.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem::InventoryItem(char new_type_item, string new_name, string new_description) : Item(new_name, new_description)
{
	this->type_item = new_type_item;
}

InventoryItem::~InventoryItem()
{
}

// Accessors ------------------------------------------------------------------------------------------------------------------------------------------------

char InventoryItem::get_type_item() const
{
	return this->type_item;
}
