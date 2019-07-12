/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** unknown comand
*/

#include "server.h"

/*!
* @brief graphical protocol command: unknown command
* @param server struct containing server infos
* @return int SUCCESS all the time [TU purpose]
*/
int suc(server_t *server)
{
	if (dprintf(server->graph->fd, "suc\n") < 0)
		return (ERROR);
	return (SUCCESS);
}
