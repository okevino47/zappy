/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** an egg was laid by a player
*/

#include "server.h"

/*!
* @brief graphical protocol command: an egg was laid by a player
* @param server struct containing server infos
* @param player current player
* @param egg egg that was laid
* @return int SUCCESS all the time [TU purpose]
*/
int enw(server_t *server, players_t *player, eggs_t *egg)
{
	if (dprintf(server->graph->fd, "enw %d %d %d %d\n", egg->id, \
	player->fd, egg->x, egg->y) < 0)
		return (ERROR);
	return (SUCCESS);
}