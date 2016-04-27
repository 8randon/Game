#include "KeyItem.h"


KeyItem::KeyItem(int new_keyNumber, string new_name) : Item(new_name)
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
