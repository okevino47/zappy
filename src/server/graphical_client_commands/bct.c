/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** content of a tile
*/

#include "server.h"

/*!
* @brief graphical protocol command: content of a tile
* @param server struct containing server infos
* @param tab array containing command args
* @return int FAILURE if args are invalid, SUCCESS if good
*/
int bct(server_t *server, char **tab)
{
	square_t *square;
	int x;
	int y;

	if (tab_size(tab) != 3 || atoi(tab[1]) >= server->x || \
	atoi(tab[2]) >= server->y) {
		sbp(server);
		return (FAILURE);
	}
	x = atoi(tab[1]);
	y = atoi(tab[2]);
	square = &(server->map[y][x]);
	if (dprintf(server->graph->fd, "bct %s %s %d %d %d %d %d %d %d\n", \
	tab[1], tab[2], square->food, square->stones->lin, \
	square->stones->der, square->stones->sib, square->stones->men, \
	square->stones->phi, square->stones->thy) < 0)
		return (ERROR);
	return (SUCCESS);
}