/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** egg laying by th eplayer
*/

#include "server.h"

/*!
* @brief graphical protocol command: egg laying by the player
* @param server struct containing server infos
* @param player current player
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pfk(server_t *server, players_t *player)
{
	if (dprintf(server->graph->fd, "pfk %d\n", player->fd) < 0)
		return (ERROR);
	return (SUCCESS);
}