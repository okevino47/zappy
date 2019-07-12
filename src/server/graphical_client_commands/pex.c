/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** expulsion
*/

#include "server.h"

/*!
* @brief graphical protocol command: expulsion of players from a tile
* @param server struct containing server infos
* @param player current player
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pex(server_t *server, players_t *player)
{
	if (dprintf(server->graph->fd, "pex %d\n", player->fd) < 0)
		return (ERROR);
	return (SUCCESS);
}