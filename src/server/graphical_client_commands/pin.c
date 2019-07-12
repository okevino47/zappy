/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player's inventory
*/

#include "server.h"

/*!
* @brief checks if pin ppo or plv can be executed
* @return players_t * NULL if cannot be executed, current player if yes
*/
players_t *check_pin_ppo_plv(char **tab, server_t *server)
{
	players_t *player;

	if (tab_size(tab) != 2) {
		sbp(server);
		return (NULL);
	}
	player = get_current_player(atoi(tab[1] + 1), server);
	if (player == NULL) {
		sbp(server);
		return (NULL);
	}
	return (player);
}

/*!
* @brief graphical protocol command: player's inventory
* @param server struct containing server infos
* @param tab array containing command args
* @return int ERROR if player does not exists, SUCCES otherwise
*/
int pin(server_t *server, char **tab)
{
	players_t *player = check_pin_ppo_plv(tab, server);

	if (player == NULL)
		return (FAILURE);
	if (dprintf(server->graph->fd, "pin %d %d %d %d %d %d %d %d %d %d\n", \
	player->fd, player->x, player->y, player->food, player->stones->lin, \
	player->stones->der, player->stones->sib, player->stones->men, \
	player->stones->phi, player->stones->thy) < 0)
		return (ERROR);
	return (SUCCESS);
}