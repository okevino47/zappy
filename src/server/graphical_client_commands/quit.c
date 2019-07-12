/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** graphical monitor deconection
*/

#include "server.h"

/*!
* @brief graphical protocol command: disconect graphical monitor
* @param server struct containing server infos
* @param tab array containing command args
* @return int SUCCESS all the time [TU purpose]
*/
int quit(server_t *server, char **tab)
{
	(void)tab;
	if (dprintf(server->graph->fd, "bye\n") < 0)
		return (ERROR);
	remove_client(server->graph->fd, server->active_set);
	server->graph = init_graph_struct();
	return (SUCCESS);
}