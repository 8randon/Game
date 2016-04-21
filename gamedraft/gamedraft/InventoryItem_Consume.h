#pragma once

#include "InventoryItem.h"


// Structs *********************************************************************************************************************************************************************************************

//- Defines the type of buff that the item holds
typedef enum consume_buff_type
{
	NONE, HEALTH
} Consume_Buff_Type;


class InventoryItem_Consume : public InventoryItem
{
public:
	InventoryItem_Consume(int new_modifier=0, Consume_Buff_Type new_buff=NONE, string new_name="\0", string new_description="\0");
	~InventoryItem_Consume();

	// Accessors ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	int get_modifier() const;
	consume_buff_type get_buff() const;

	// Public Member Functions ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	void use(); //TODO Add a reference to the character class once it is created

private:
	int modifier;
	Consume_Buff_Type buff;
};