/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** end of incantation
*/

#include "server.h"

/*!
* @brief graphical protocol command: end of an incantation
* @param server struct containing server infos
* @param player current player
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pie_success(server_t *server, players_t *player)
{
	if (dprintf(server->graph->fd, "pie %d %d ok\n", player->x, \
	player->y) < 0)
		return (ERROR);
	return (SUCCESS);
}

int pie_failure(server_t *server, players_t *player)
{
	if (dprintf(server->graph->fd, "pie %d %d ko\n", player->x, \
	player->y) < 0)
		return (ERROR);
	return (SUCCESS);
}