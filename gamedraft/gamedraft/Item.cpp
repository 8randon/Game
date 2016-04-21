#include "Item.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Item::Item(string new_name, string new_destription)
{
  this->name = new_name;
  this->description = new_destription;
}

Item::~Item()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

string Item::get_name() const
{
	return this->name;
}

string Item::get_description() const
{
	return this->description;
}
