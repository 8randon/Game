#include "InventoryItem.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem::InventoryItem(string new_name, char new_type_item) : Item(new_name)
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
