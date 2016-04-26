/*
	The wrapper-class for storing user save-data. Keeps information on the player's last saved status and level stores information not currently being used
	(i.e. the data of other users besides the ones currently playing the game) onto an encrypted text file. The functions used to encrypt and decrypt the 
	file are also located within this class.

	Written by Jensen Reitz
*/

#pragma once

#include <fstream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Player.h"


class User
{
public:
	User(string const &new_username="\0", string const &new_password="\0");
	~User();

	// Accessors --------------------------------------------------------------------------------------------------------------------------------------------

	int get_currentLevel() const;
	Player get_saved_player();

	//Mutators ----------------------------------------------------------------------------------------------------------------------------------------------

	bool save(int updatedLevel, Player &updatedPlayer);

	// Public Member Functions ------------------------------------------------------------------------------------------------------------------------------
	
	bool loadSave(string const &username, string const &password);

private:
	int currentLevel, saveFile_line;
	string username, password;
	Player saved_player;

	//Private Member Functions ------------------------------------------------------------------------------------------------------------------------------

	void decode(string &str);
	int encode(int saved_level, Player &saved_player);
	int allocateSaveLine();
	int loadToFile(string const &encodedString);
	bool fetch(string const &username, string const &password);
	Player parsePlayerInfo(string const &str, size_t start);
};

