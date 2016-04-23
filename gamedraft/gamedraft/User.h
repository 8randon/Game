/*
	The wrapper-class for storing user save-data. Keeps information on the player's last saved status and level stores information not currently being used
	(i.e. the data of other users besides the ones currently playing the game) onto an encrypted text file. The functions used to encrypt and decrypt the 
	file are also located within this class.

	Written by Jensen Reitz
*/

#pragma once

#include "Player.h"


class User
{
public:
	User();
	~User();

	// Accessors --------------------------------------------------------------------------------------------------------------------------------------------

	int get_currentLevel() const;
	Player get_saved_player();

	//Mutators

	//- Accepts an int representing the level that the user is currently on and a reference to the user's character to be saved within the wrapper class
	void save(int updatedLevel, Player &const updatedPlayer);


private:
	int currentLevel;
	string username, password;
	Player saved_player;
};

