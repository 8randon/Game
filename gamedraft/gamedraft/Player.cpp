#include "Player.h"

//hold/consume (h/c), name, buff (int), modifier
string Player::loadInventory()
{
	string inventoryData;
	InventoryItem *pCurr = this->inventory;

	while(pCurr++)
	{
		inventoryData += ",";

		if(pCurr->get_type_item()=='h')
		{
			inventoryData += "h" + ',' + pCurr->get_name();
			inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(pCurr)->get_buff();
			inventoryData += "," + dynamic_cast<InventoryItem_Hold *>(pCurr)->get_modifier();
		}
		else if(pCurr->get_type_item()=='c')
		{
			inventoryData += "c" + ',' + pCurr->get_name();
			inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(pCurr)->get_buff();
			inventoryData += "," + dynamic_cast<InventoryItem_Consume *>(pCurr)->get_modifier();
		}
	}

	return inventoryData;
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
	if (distance(enemy))
	{
		while(enemy->gethp() != 0)
			dmg = str - enemy->getstr();
			enemy->set_hp(enemy->gethp() - dmg);
	}
}