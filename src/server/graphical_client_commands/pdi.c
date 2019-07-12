/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** death of a player
*/

#include "server.h"

/*!
* @brief graphical protocol command: daeth of a player
* @param server struct containing server infos
* @param player current player
* @param message message broadcasted
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pdi(server_t *server, players_t *player)
{
	if (dprintf(server->graph->fd, "pdi %d\n", player->fd) < 0)
		return (ERROR);
	return (SUCCESS);
}