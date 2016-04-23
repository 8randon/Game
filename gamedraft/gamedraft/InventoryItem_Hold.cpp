#include "InventoryItem_Hold.h"


// Constructor/Destructor ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

InventoryItem_Hold::InventoryItem_Hold(float new_durability, Hold_Buff_Type new_buff, float new_modifier, string new_name, string new_description) : InventoryItem(new_name, new_description)
{
	this->durability = new_durability;
	this->buff = new_buff;
}

InventoryItem_Hold::~InventoryItem_Hold()
{
}

// Accessors -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

float InventoryItem_Hold::get_modifier() const
{
	return this->modifier;
}

// Public Member Functions -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void InventoryItem_Hold::equip(Character &character)
{
	int currAttribute, attributeMod;

	switch(this->buff)
	{
	case ARMOR: 
		currAttribute = character.getarmor();

		attributeMod = (int)(currAttribute*(this->modifier));

		character.set_armor(currAttribute+attributeMod);

		break;
	case ATTACK_DAMAGE:
		currAttribute = character.getstr();

		attributeMod = (int)(currAttribute*(this->modifier));

		character.set_str(currAttribute+attributeMod);
		break;
	case HEALTH:
		currAttribute = character.gethp();

		attributeMod = (int)(currAttribute*(this->modifier));

		character.set_hp(currAttribute+attributeMod);
		break;
	}
}

//TODO write definition
void InventoryItem_Hold::dequip(Character &character)
{

}
