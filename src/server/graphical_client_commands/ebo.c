/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player connection for an egg
*/

#include "server.h"

/*!
* @brief graphical protocol command: player connection for an egg
* @param [in] server struct containing server infos
* @param [in] egg current egg
* @return int SUCCESS all the time [TU purpose]
*/
int ebo(server_t *server, eggs_t *egg)
{
	if (dprintf(server->graph->fd, "ebo %d\n", egg->id) < 0)
		return (ERROR);
	return (SUCCESS);
}

