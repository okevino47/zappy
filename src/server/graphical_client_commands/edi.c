/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** death of an hatched egg
*/

#include "server.h"

/*!
* @brief graphical protocol commad: death of an hatched egg
* @param server struct containing server infos
* @param egg current egg
* @return int SUCCESS all the time [TU purpose]
*/
int edi(server_t *server, eggs_t *egg)
{
	if (dprintf(server->graph->fd, "edi %d\n", egg->id) < 0)
		return (ERROR);
	return (SUCCESS);
}