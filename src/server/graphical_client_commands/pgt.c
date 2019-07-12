/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ressource collecting
*/

#include "server.h"

/*!
* @brief graphical protocol command: ressource collecting
* @param server struct contaning server infos
* @param player current player
* @param ressource ressource taken
* @return int SUCCESS all the time ERROR if dprntf error
*/
int pgt(server_t *server, players_t *player, int ressource)
{
	if (dprintf(server->graph->fd, "pgt %d %d\n", player->fd, \
	ressource) < 0)
		return (ERROR);
	return (SUCCESS);
}