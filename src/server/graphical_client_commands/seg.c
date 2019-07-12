/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** end of game
*/

#include "server.h"

/*!
* @brief graphical protocol command: end of game
* @param server struct containing server infos
* @param team winning team
* @return int SUCCESS all the time [TU purpose]
*/
int seg(server_t *server, teams_t *team)
{
	if (dprintf(server->graph->fd, "seg %s\n", team->name) < 0)
		return (ERROR);
	return (SUCCESS);
}