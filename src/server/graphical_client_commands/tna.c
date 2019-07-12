/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** name of all the teams
*/

#include "server.h"

/*!
* @brief graphical protocol command: name of all the teams
* @param server struct containing server infos
* @param tab array containing command args
* @return int SUCCESS all the time [TU purpose]
*/
int tna(server_t *server, char **tab)
{
	teams_t *tmp = server->teams;

	(void)tab;
	for (; tmp != NULL; tmp = tmp->next) {
		if (dprintf(server->graph->fd, "tna %s\n", tmp->name) < 0)
			return (ERROR);
	}
	return (SUCCESS);
}