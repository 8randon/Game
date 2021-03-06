#include "InventoryItem_Hold.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Hold::InventoryItem_Hold(int new_buff, int new_modifier, string new_name, char new_type_item) : InventoryItem(new_name, new_type_item)
{
	this->modifier = new_modifier;
	this->buff = (Hold_Buff_Type)new_buff; 
}

InventoryItem_Hold::~InventoryItem_Hold()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int InventoryItem_Hold::get_modifier() const
{
	return this->modifier;
}

int InventoryItem_Hold::get_buff() const
{
	return (int)this->buff;
}

// Public Member Functions -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//- Assigns attribute buffs to the character "holding" the item
//- Accepts a reference to the Character, passing the modified values back through once the function call is complete
//PRECONDITION: The character must have the attribute that will be modified as a member, this will not be checked within the function
void InventoryItem_Hold::equip(Character &character)
{
	int currAttribute, attributeMod;

	switch(this->buff)
	{
	case ARMOR: 
		currAttribute = character.getarmor();

		character.set_armor(currAttribute+(this->modifier));

		break;
	case ATTACK_DAMAGE:
		currAttribute = character.getstr();

		attributeMod = (int)(currAttribute*(this->modifier/100));

		character.set_str(currAttribute+attributeMod);
		break;
	case HEALTH:
		currAttribute = character.gethp();

		character.set_hp(currAttribute+(this->modifier));
		break;
	}
}

//TODO
//- Takes away the attribute buffs that would be assigned when the item was equipped
//- Accepts a reference to the Character, passing the modified values back through once the function call is complete
//PRECONDITION: The character must have the attribute that will be modified as a member, this will not be checked within the function
void InventoryItem_Hold::dequip(Character &character)
{
	int currAttribute, attributeMod;

	switch(this->buff)
	{
	case ARMOR:
		currAttribute = character.getarmor();

		character.set_armor(currAttribute+(this->modifier));

		break;
	case ATTACK_DAMAGE:
		currAttribute = character.getstr();

		attributeMod = (int)(currAttribute*(this->modifier/100));

		character.set_str(currAttribute+attributeMod);
		break;
	case HEALTH:
		currAttribute = character.gethp();

		character.set_hp(currAttribute+(this->modifier));
		break;
	}
}