#include "User.h"


User::User(string const &new_username, string const &new_password)
{
	this->username = new_username;
	this->password = new_password;

	this->saved_player = *(new Player());

	this->saveFile_line = this->allocateSaveLine();
}

User::~User()
{
}

// Accessors ----------------------------------------------------------------------------------------------------------------------------------------------------

int User::get_currentLevel() const
{
	return this->currentLevel;
}

Player User::get_saved_player()
{
	return this->saved_player;
}

// Mutators -------------------------------------------------------------------------------------------------------------------------------------------------

//- Accepts an int representing the level that the user is currently on and a reference to the user's character to be saved within the wrapper class
//- Returns true if the data was successfully saved
//- Returns false if the save was unsuccessful
bool User::save(int updatedLevel, Player &updatedPlayer)
{
	if(encode(updatedLevel, updatedPlayer)==0) //If the encoding and loading to save file is successful
	{
		//Copy over the updated level
		this->currentLevel = updatedLevel;

		//Copy over the instance of the User's character
		Player updatedPlayer_Copy = *(new Player(updatedPlayer));
		Player temp = this->saved_player;

		this->saved_player = updatedPlayer_Copy;

		//Delete the old saved_player
		temp.~Player();

		return true;
	}
	else
		return false;

}

// Public Member Functions --------------------------------------------------------------------------------------------------------------------------------------

//- Calls and returns the value from fetch() on a public level
bool User::loadSave(string const &username, string const &password)
{
	return fetch(username, password);
}

// Private Member Functions -------------------------------------------------------------------------------------------------------------------------------------

//- Passes in a string by reference, decrypts it using the encryption key that is determined within the function, and passes the dcrypted version back out
//	through reference
void User::decode(string &str)
{
	int decryptKey; //The encryption ket that will be found and then used to decrypt the string

	//Find the encyrptionKey
	for(size_t i=0; i<str.length(); i++)
	{
		if(i==str.at(i))
			decryptKey = (int)i;
	}

	//The string to translate decrypted information onto
	string decrypted;

	//Decrypt
	for(size_t i=0; i<str.length(); i++)
	{
		if(str.at(i)!='\0' && str.at(i)!='\n') //Check to see if the current index is the null or newline character at the end of the string
		{
			if(str.at(i)-decryptKey<33)
				decrypted += (char *)((126+(str.at(i)-32))-decryptKey);
			else
				decrypted += (char *)(str.at(i)-decryptKey);
		}
		else
			decrypted += str.at(i);
	}

	//Transfer the decrypted string back to str
	str = decrypted;
}

//- Takes the current user data that is passed in through parameters and parses it together into an encyrpted string
//- Loads the encyrpted string into the save file after rewriting it through loadToFile()
//- Returns the value that is passed back from loadToFile()
//PRECONDITION: The only type of character that can be passed through is of Player type becase that is the only type of character that the user can play as
int User::encode(int saved_level, Player &saved_player)
{
	srand((unsigned int)time(NULL));

	//Save data in order of:
	//username, password, current level, max health, current health, strength, armor, inventory
	string userData = this->username + "," + this->password + "," + (char *)saved_player.getmhp() + "," + (char *)saved_player.gethp() + "," + 
		(char *)saved_player.getstr() + "," + (char *)saved_player.getarmor() + saved_player.loadInventory() + saved_player.loadKeys();

	//Generate an encryption key for encoding the saved data
	int encryptKey = rand()%9 + 1;
	string encoded;

	//Encode the string
	for(size_t i=0; i<userData.length(); i++)
	{
		if(i==encryptKey)
			encoded += encryptKey;

		if(userData.at(i)!='\0' && userData.at(i)!='\n') //Check to see if the current index is the null or newline character at the end of the string
		{
			if((userData.at(i)+encryptKey)>126)
				encoded += (char *)(32 + ((userData.at(i)+encryptKey)-126)); //The lowest value a character in this string can have is 33
			else
				encoded += (char *)(userData.at(i)+encryptKey);
		}
		else
			encoded += userData.at(i);
	}

	//Load the encoded string into the file
	return loadToFile(encoded);
}

//- Searches through the save file for the next available line to put data on
//PRECONDITION: Only called when the current user decides to create a new save
int User::allocateSaveLine()
{
	int i = 0; //Counter Variable for loop
	char buf[100];
	fstream fstr("SaveFiles.txt", ios::in);

	while(!fstr.eof())
	{
		fstr.getline(buf, 100);
		i++;
	}

	return (i+1);
}

//- Writes the encyrpted string into the save file over the same line as the previous save was located
//- Loads every line of saved data from SaveFiles.txt into a newly created file except for the old save for the current user, which is replaced by the 
//	new one. The new file is then renamed to overwrite SaveFiles.txt with it's data
//- Returns the value passed back from rename()
int User::loadToFile(string const &encodedString)
{
	int i = 0; //Counter Variable for loops
	fstream fstr("SaveFiles.txt", ios::in), new_fstr("nSaveFiles.txt");

	//Load the other saved data into the new file along with the newly saved data
	while(!fstr.eof())
	{
		if(i==this->saveFile_line)
			new_fstr << encodedString << endl;
		else
		{
			string temp;

			getline(fstr, temp);

			new_fstr << temp;
		}
	}

	fstr.close();
	new_fstr.close();

	//TODO change implementation to remove the older file and then rename the new one
	//Rename the newly saved file to match the original and return the success code
	return rename("nSaveFiles.txt", "SaveFiles.txt");
}

//- Searches through the save file, decrypting each line at a time, to find and fetch the data for a returning user's saved data
//- If a match is found, the data is parsed and loaded into the user's object; bool value true is returned
//- If a match is not found, bool value false is returned
bool User::fetch(string const &username, string const &password)
{
	int i = 0; //Counter variable for loops
	string fetched_username, fetched_password;
	fstream fstr("SaveFiles.txt", ios::in);

	while(!fstr.eof())
	{
		string str;

		//Grab data string and decode
		getline(fstr, str);
		decode(str);

		//Parse for username and password
		size_t a, b, c;
		a = str.find(',', 0);
		b = str.find(',', a);
		c = str.find(',', b);

		fetched_username = str.substr(0, a);
		fetched_password = str.substr(a+1, b-(a+1));

		if(fetched_username==username && fetched_password==password)
		{
			this->username = username;
			this->password = username;
			this->currentLevel = (int)str.at(b+1);
			this->saved_player = parsePlayerInfo(str, c+1);
			this->saveFile_line = i;

			return true;
		}

		i++;
	}

	return false;
}


Player User::parsePlayerInfo(string const &str, size_t start)
{
	//String is stored in this configuration: username, password, current level, max health, current health, strength, armor, inventory

	string maxHP, currentHP, strength, armor;
	vector<string> strings; //Vector to hold substrings of all the parsed data
	size_t a = start, b;
	Player *newPlayer = new Player();

	do
	{
		string temp; //Temporary string to read in data

		b = str.find(',', a);

		temp = str.substr(a, (b-a));
		a = b + 1;

		strings.push_back(temp); //Push into vector

	} while(a>0); //While there is still data to read (Will loop back to the beginning of str once read all the way through)

	//Set the initial player attribute values
	newPlayer->set_mhp(std::stoi(strings.at(0)));
	newPlayer->set_hp(std::stoi(strings.at(1)));
	newPlayer->set_str(std::stoi(strings.at(2)));
	newPlayer->set_armor(std::stoi(strings.at(3)));

	//Parse data for inventory
	//hold/consume (h/c), name, buff (int), modifier
	size_t i = 4;

	while(strings.at(i)!="*")
	{
		InventoryItem *new_item;

		//Check for if the item is consumable or equipable
		if(strings.at(i)=="h")
			new_item = new InventoryItem_Hold(stoi(strings.at(i+2)), stoi(strings.at(i+3)), 'h', strings.at(i+1));
		else
			new_item = new InventoryItem_Consume(stoi(strings.at(i+2)), stoi(strings.at(i+3)), 'c', strings.at(i+1));

		try
		{
			newPlayer->addInventory(*new_item);
		}
		catch(const std::out_of_range &oor) //If there is no more room in the inventory
		{
			cout << "Out of Range error: " << oor.what() << endl;
			cout << "Inventory Limit has been reached" << endl;
			break; //Exit the loop to avoid more problems
		}

		i += 4;
	}

	while(strings.at(i++)!="*") //Loop through until the sentinel character if the above loop had to terminate prematurely
	{ }

	//Parse key information
	for(size_t j=i+1; j<strings.size(); j+=2)
	{
		KeyItem newKey(stoi(strings.at(i+1)), strings.at(i));

		try
		{
			newPlayer->addKeyItem(newKey);
		}
		catch(const std::out_of_range &oor)
		{
			cout << "Out of Range error: " << oor.what() << endl;
			cout << "KeyItem Limit has been reached" << endl;
			break; //Exit the loop to avoid more problems
		}
	}

	return *newPlayer;
}
