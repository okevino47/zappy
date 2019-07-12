/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** connection of a new player
*/

#include "server.h"

/*!
* @brief graphical protocol : connection of a new player
* @param server struct containig server infos
* @param team current team
* @param player current player
* @return int SUCCESS all the time, ERROR if dprintf failed
*/
int pnw(server_t *server, teams_t *team, players_t *player)
{
	if (dprintf(server->graph->fd, "pnw #%d %d %d %d %d %s\n", \
	player->fd, player->x, player->y, player->direction, \
	player->level, team->name) < 0)
		return (ERROR);
	return (SUCCESS);
}