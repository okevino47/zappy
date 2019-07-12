/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** exec commands
*/

#include "server.h"

/*!
* @brief browses actions and updates cycles, exec commands if necessary
* @param tmp pointer to action chained list of current player
* @param server struct containing server infos
* @param player current player
* @return int SUCCESS all the time
*/
int browse_actions(actions_t *tmp, server_t *server, players_t *player)
{
	fp *func_array = func_array_init();

	for (; tmp != NULL; tmp = tmp->next) {
		tmp->cycles++;
		if (tmp->cycles == tmp->max_cycles && tmp->action >= 0 && \
			tmp->action <= 11) {
			func_array[tmp->action](server, tmp, player->fd);
			delete_action_elem(tmp, player);
		}
	}
	return (SUCCESS);
}
/*!
* @brief browses players
* @param server struct containing server infos
* @param player pointer to current player
*/
int browse_players(server_t *server, players_t *player, fd_set *active_set)
{
	actions_t *tmp;

	if (player == NULL)
		return (ERROR);
	for (; player != NULL; player = player->next) {
		tmp = player->actions;
		player->life--;
		if (player->life % 126 == 0)
			player->food--;
		if (player->life == 0) {
			pdi(server, player);
			dprintf(player->fd, "dead\n");
			remove_client(player->fd, active_set);
			delete_player_square(player, server);
			delete_player_elem(player, server);
			return (SUCCESS);
		}
		browse_actions(tmp, server, player);
	}
	return (SUCCESS);
}

/*!
* @brief browse eggs in current team and handles hatching of it
* @param team current team
*/
void browse_eggs(teams_t *team, server_t *server)
{
	eggs_t *tmp = team->eggs;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp->time++;
		if (tmp->time == 600) {
			eht(server, tmp);
			tmp->ready = true;
			team->max_players++;
		}
	}
}

/*!
* @brief browse all players of all teams
* @param server struct containing server infos
*/
void update_cycles(server_t *server, fd_set *active_set)
{
	teams_t *tmp = server->teams;
	players_t *tmp_p;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp_p = tmp->players;
		browse_players(server, tmp_p, active_set);
		browse_eggs(tmp, server);
	}
}