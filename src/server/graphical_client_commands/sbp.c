/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** bad parameters
*/

#include "server.h"

/*!
* @brief graphical protocol command: bad parameters
* @param server struct containing server infos
* @return int SUCCESS all the time [TU purpose]
*/
int sbp(server_t *server)
{
	if (dprintf(server->graph->fd, "sbp\n") < 0)
		return (ERROR);
	return (SUCCESS);
}