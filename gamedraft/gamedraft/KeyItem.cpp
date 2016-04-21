#include "KeyItem.h"


KeyItem::KeyItem(int new_keyNumber, string new_name, string new_description) : Item(new_name, new_description)
{
}

KeyItem::~KeyItem()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int KeyItem::get_keyNumber() const
{
	return this->keyNumber;
}
