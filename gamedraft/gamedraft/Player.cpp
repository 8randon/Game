#include "Player.h"

//-	Converts the player's inventory into a string to be passed back and encrypted in User::encode()
//Written by Jensen Reitz
string Player::loadInventory()
{
	//String is stored in this configuraation: hold/consume (h/c), name, buff (int), modifier

	string inventoryData;

	for(int i=0; i<10; i++)
	{
		if(this->inventory[i])
		{
			inventoryData += ",";

			if(this->inventory[i]->get_type_item()=='h')
			{
				inventoryData += "h" + ',' + this->inventory[i]->get_name();
				inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(this->inventory[i])->get_buff();
				inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(this->inventory[i])->get_modifier();
			}
			else if(this->inventory[i]->get_type_item()=='c')
			{
				inventoryData += "c" + ',' + this->inventory[i]->get_name();
				inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(this->inventory[i])->get_buff();
				inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(this->inventory[i])->get_modifier();
			}
		}
	}

	return inventoryData;
}

//-	Converts the player's keypuch into a string to be passed back and encrypted in User::encode()
//Written by Jensen Reitz
string Player::loadKeys()
{
	//String is stored in the format: name, keyNumber

	string keyData;

	keyData += ",*,"; //Sentinel character for the decryption to know when the KeyItems begin

	for(int i=0; i<5; i++)
	{
		if(this->keypouch[i])
		{
			keyData += "," + this->keypouch[i]->get_name() + ",";
			keyData += this->keypouch[i]->get_keyNumber();
		}
	}

	return keyData;
}

//- Adds an ImventoryItem into the player's inventory
//- Returns true if the key is successfuly stored, false if there is no more room
//Written by Jensen Reitz
bool Player::addInventory(InventoryItem *newItem)
{
	for(int i=0; i<10; i++)
	{
		if(!(this->inventory[i]))
		{
			(this->inventory[i]) = newItem;
			return true;
		}
	}

	return false;
}

//- Adds a KeyItem into the player's keypouch
//- Returns true if the key is successfuly stored, false if there is no more room
//Written by Jensen Reitz
bool Player::addKeyItem(KeyItem *newKey)
{
	for(int i=0; i<5; i++)
	{
		if(!(this->keypouch[i]))
		{
			(this->keypouch[i]) = newKey;
			return true;
		}
	}

	return false;
}

void Player::levelup()
{
	while (xp > 0)
	{
		int opt;
		int opt2;
		cout << "Level UP!\n1. HP \n2.Str \n3. Mgc" << endl;
		cin >> opt;
		if (opt == 1)
		{
			while (opt2 > opt)
			{
				cout << "XP amount: ";
				cin >> opt2;
				cout << "INVALID" << endl;
			}
				hp = hp + opt2;
		}
		if (opt == 2)
		{
			while (opt2 > opt)
			{
				cout << "XP amount: ";
				cin >> opt2;
				cout << "INVALID" << endl;
			}
			str = str + opt2;
		}
		if (opt == 3)
		{
			while (opt2 > opt)
			{
				cout << "XP amount: ";
				cin >> opt2;
				cout << "INVALID" << endl;
			}
			mgc = mgc + opt2;
		}
	}
}

void Player::attack(Character *&enemy)
{
	int dmg = 0;
	if (distance(*enemy))
	{
		if(enemy->gethp() != 0)
		{
			dmg = this->str - (this->str*(enemy->getarmor()/100));
			
			enemy->set_hp(enemy->gethp() - dmg);
		}
	}
}