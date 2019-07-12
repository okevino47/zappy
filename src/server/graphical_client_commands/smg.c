/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** message from server
*/

#include "server.h"

/*!
* @brief graphical protocol command: message from server
* @param server struct containing server infos
* @param mess message to send
* @return int SUCCESS all the time [TU purpose]
*/
int smg(server_t *server, char *mess)
{
	if (dprintf(server->graph->fd, "smg %s\n", mess) < 0)
		return (ERROR);
	return (SUCCESS);
}