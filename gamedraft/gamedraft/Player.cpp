#include "Player.h"


string Player::loadInventory()
{
	//String is stored in this configuraation: hold/consume (h/c), name, buff (int), modifier

	int i = 0; //Counter variable for loops
	string inventoryData;
	InventoryItem *pCurr = this->inventory;

	while((pCurr+i) && i<10)
	{
		inventoryData += ",";

		if(pCurr->get_type_item()=='h')
		{
			inventoryData += "h" + ',' + (pCurr+i)->get_name();
			inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(pCurr+i)->get_buff();
			inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(pCurr+i)->get_modifier();
		}
		else if(pCurr->get_type_item()=='c')
		{
			inventoryData += "c" + ',' + (pCurr+i)->get_name();
			inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(pCurr+i)->get_buff();
			inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(pCurr+i)->get_modifier();
		}

		i++;
	}

	return inventoryData;
}

string Player::loadKeys()
{
	//String is stored in the format: name, keyNumber

	int i = 0; //Counter variable for loops
	string keyData;
	KeyItem *pCurr = this->keypouch;

	keyData += ",*,"; //Sentinel character for the decryption to know when the KeyItems begin

	while((pCurr+i) && i<5)
	{
		keyData += "," + (pCurr+i)->get_name() + ",";
		keyData += (pCurr+i)->get_keyNumber();

		i++;
	}

	return keyData;
}

void Player::addInventory(InventoryItem newItem)
{
	InventoryItem *pCurr = this->inventory;

	while(pCurr++) //Loop until the next inventory slot is open
	{ }

	*pCurr = newItem;
}

void Player::addKeyItem(KeyItem newKey)
{
	KeyItem *pCurr = this->keypouch;

	while(pCurr++)
	{ }

	*pCurr = newKey;
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