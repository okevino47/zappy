/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player's position
*/

#include "server.h"

/*!
* @brief graphical protocol command: player's position
* @param server struct containing server infos
* @param tab array containing command args
* @return int ERROR if player does not exists, SUCCES otherwise
*/
int ppo(server_t *server, char **tab)
{
	players_t *player = check_pin_ppo_plv(tab, server);

	if (player == NULL)
		return (FAILURE);
	if (dprintf(server->graph->fd, "ppo %d %d %d %d\n", player->fd, \
	player->x, player->y, player->direction) < 0)
		return (ERROR);
	return (SUCCESS);
}
