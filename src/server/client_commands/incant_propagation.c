/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incant propagation
*/

#include "server.h"

/*!
* @brief propagates elevation underway message to all concerned players
* @param server struct containing server infos
* @param player current player instanciating elevation
* @return int SUCCESS all the time or ERROR in case of dpritnf error
*/
int elevation_underway_propagate(server_t *server, players_t *player)
{
	square_t *square = &(server->map[player->y][player->x]);
	node_player_t *tmp = square->players;

	for (; tmp != NULL; tmp = tmp->next) {
		if (dprintf(tmp->player->fd, "Elevation underway\n") < 0)
			return (ERROR);
	}
	return (SUCCESS);
}

/*!
* @brief propagates complete elevation message to all concerned players
* @param server struct containing server infos
* @param player current player instanciating elevation
* @return int SUCCESS all the time or ERROR in case of dpritnf error
*/
int end_elevation_propagate(server_t *server, players_t *player)
{
	square_t *square = &(server->map[player->y][player->x]);
	node_player_t *tmp = square->players;

	for (; tmp != NULL; tmp = tmp->next) {
		if (dprintf(tmp->player->fd, REPL_OK_INCANT, \
		tmp->player->level) < 0)
			return (ERROR);
	}
	return (SUCCESS);
}

/*!
* @brief propagates failed elevation message to all concerned players
* @param server struct containing server infos
* @param player current player instanciating elevation
* @return int SUCCESS all the time or ERROR in case of dpritnf error
*/
int fail_elevation_propagate(server_t *server, players_t *player)
{
	square_t *square = &(server->map[player->y][player->x]);
	node_player_t *tmp = square->players;

	for (; tmp != NULL; tmp = tmp->next) {
		if (dprintf(tmp->player->fd, REPL_KO) < 0)
			return (ERROR);
	}
	return (SUCCESS);
}