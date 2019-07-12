/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** commands array
*/

#include "server.h"

/*!
* @brief inits command array with indexes corresponding to macros
* @return char ** the array of commands
*/
char **command_array(void)
{
	static char *tab[13];

	tab[0] = CMD_CONN_NBR;
	tab[1] = CMD_INVENTORY;
	tab[2] = CMD_FWD;
	tab[3] = CMD_RIGHT;
	tab[4] = CMD_LEFT;
	tab[5] = CMD_LOOK;
	tab[6] = CMD_BROAD;
	tab[7] = CMD_EJECT;
	tab[8] = CMD_TAKE;
	tab[9] = CMD_SET;
	tab[10] = CMD_FORK;
	tab[11] = CMD_INCANT;
	tab[12] = NULL;
	return (tab);
}

/*!
* @brief initializes an array of functions pointer according to macros ranges
* @return fp* pointer to the array of functions
*/
fp *func_array_init(void)
{
	static fp func_array[13];

	func_array[0] = connect_nbr_command;
	func_array[1] = inventory_command;
	func_array[2] = forward_command;
	func_array[3] = right_command;
	func_array[4] = left_command;
	func_array[5] = look_command;
	func_array[6] = broadcast_command;
	func_array[7] = eject_command;
	func_array[8] = take_command;
	func_array[9] = set_command;
	func_array[10] = fork_command;
	func_array[11] = incantation_command;
	func_array[12] = NULL;
	return (func_array);
}

/*!
* @brief creates an array of all existing stones
* @return char ** array of all existing stones
*/
char **name_stones_array(void)
{
	static char *tab[7];

	tab[0] = "linemate";
	tab[1] = "deraumere";
	tab[2] = "sibur";
	tab[3] = "mendiane";
	tab[4] = "phiras";
	tab[5] = "thystame";
	tab[6] = NULL;
	return (tab);
}
