#include "Player.h"

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