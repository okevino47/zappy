/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map size
*/

#include "server.h"

/*!
* @brief graphical protocol command: map size
* @param server struct containing server infos
* @param tab array containing command args
* @return int SUCCESS all the time [TU purpose]
*/
int msz(server_t *server, char **tab)
{
	(void)tab;
	if (dprintf(server->graph->fd, "msz %d %d\n", server->x, \
	server->y) < 0)
		return (ERROR);
	return (SUCCESS);
}