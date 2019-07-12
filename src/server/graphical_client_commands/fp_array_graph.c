/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fp array graph
*/

#include "server.h"

/*!
* @brief inits func pointer array for graphical commands
* @return fp_g * pointer to initialized array
*/
fp_g *fp_init_graph(void)
{
	static fp_g fp[9];

	fp[0] = msz;
	fp[1] = bct;
	fp[2] = mct;
	fp[3] = tna;
	fp[4] = ppo;
	fp[5] = plv;
	fp[6] = pin;
	fp[7] = quit;
	fp[8] = NULL;
	return (fp);
}

/*!
* @brief inits a string array containing all commands name for graphical prot
* @return char ** initialized array
*/
char **command_array_graph(void)
{
	static char *array[9];

	array[0] = "msz";
	array[1] = "bct";
	array[2] = "mct";
	array[3] = "tna";
	array[4] = "ppo";
	array[5] = "plv";
	array[6] = "pin";
	array[7] = "quit";
	array[8] = NULL;
	return (array);
}