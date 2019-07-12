/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** content of the map
*/

#include "server.h"

/*!
* @brief sets array for bct call in mct
* @param tab array to init
* @param i equivalent to y
* @param j equivalent to x
* @return char ** the initialized array
*/
char **set_tab_bct(char **tab, int i, int j)
{
	char *x = malloc(sizeof(char) * 12);
	char *y = malloc(sizeof(char) * 12);

	memset(y, 0, 11);
	memset(x, 0, 11);
	sprintf(x, "%d", j);
	sprintf(y, "%d", i);
	tab[1] = x;
	tab[2] = y;
	tab[3] = NULL;
	return (tab);
}

/*!
* @brief graphical protocol command: content of the map
* @param server struct containing server infos
* @param tab array containing command args
* @return int SUCCESS all the time [TU purpose]
*/
int mct(server_t *server, char **tab)
{
	char *tab_bct[4];

	(void)tab;
	tab_bct[0] = malloc(sizeof(char) * 4);
	strcpy(tab_bct[0], "bct\0");
	for (int i = 0; i < server->y; i++) {
		for (int j = 0; j < server->x; j++) {
			set_tab_bct(tab_bct, i, j);
			bct(server, tab_bct);
		}
	}
	return (SUCCESS);
}