/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** egg hatching
*/

#include "server.h"

/*!
* @brief graphical protocol command: egg hatching
* @param server struct containing server infos
* @param egg current egg
* @return int SUCCESS all the time [TU purpose]
*/
int eht(server_t *server, eggs_t *egg)
{
	if (dprintf(server->graph->fd, "eht %d\n", egg->id) < 0)
		return (ERROR);
	return (SUCCESS);
}