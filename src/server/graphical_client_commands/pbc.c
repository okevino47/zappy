/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include "server.h"

/*!
* @brief graphical protocol command: broadcast of message
* @param server struct containing server infos
* @param player current player
* @param message message broadcasted
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pbc(server_t *server, players_t *player, char *message)
{
	if (dprintf(server->graph->fd, "pbc %d %s\n", player->fd, message) < 0)
		return (ERROR);
	return (SUCCESS);
}

