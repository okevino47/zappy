/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ressource dropping
*/

#include "server.h"

/*!
* @brief graphical protocol command: ressource dropping
* @param server struct containing serbvr infos
* @param player current player
* @param ressource ressources dropped
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pdr(server_t *server, players_t *player, int ressource)
{
	if (dprintf(server->graph->fd, "pdr %d %d\n", player->fd, \
	ressource) < 0)
		return (ERROR);
	return (SUCCESS);
}