#include "User.h"


User::User()
{
}


User::~User()
{
}

// Accessors ------------------------------------------------------------------------------------------------------------------------------------------------

int User::get_currentLevel() const
{
	return this->currentLevel;
}

Player User::get_saved_player()
{
	return this->saved_player;
}

// Mutators -------------------------------------------------------------------------------------------------------------------------------------------------

void User::save(int updatedLevel, Player &const updatedPlayer)
{
	//Copy over the updated level
	this->currentLevel = updatedLevel;

	//Copy over the instance of the User's character
	Player updatedPlayer_Copy = *(new Player(updatedPlayer));
	Player temp = this->saved_player;

	this->saved_player = updatedPlayer_Copy;

	//Delete the old saved_player
	delete &temp;
}
