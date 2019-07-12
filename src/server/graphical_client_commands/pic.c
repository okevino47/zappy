/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** start of an icantation
*/

#include "server.h"

/*!
* @brief graphical protocol command: start of an incantation
* @param server struct containing server infos
* @param player current player
* @return int SUCCESS all the time ERROR if dprintf error
*/
int pic(server_t *server, players_t *player)
{
	square_t *square = &(server->map[player->y][player->x]);

	if (dprintf(server->graph->fd, "pic %d %d %d", player->x, player->y, \
	player->level) < 0)
		return (ERROR);
	for (node_player_t *tmp = square->players; tmp != NULL;
	tmp = tmp->next) {
		if (dprintf(server->graph->fd, "%d", tmp->player->fd))
			return (ERROR);
		if (tmp->next != NULL)
			dprintf(server->graph->fd, " ");
	}
	if (dprintf(server->graph->fd, "\n") < 0)
		exit(ERROR);
	return (SUCCESS);
}