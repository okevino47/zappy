/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** end game
*/

#include "server.h"

/*!
* @brief browses all players and closes them after saying that game has ended
* @param tmp_p current player list of team
* @param team_win team that won
* @param server struct containing server infos
* @param active_set set of file descriptors for select
* @return int SUCCESS all the time [TU purpose]
*/
int browse_players_win(players_t *tmp_p, teams_t *team_win, server_t *server, \
		fd_set *active_set)
{
	for (; tmp_p != NULL; tmp_p = tmp_p->next) {
		if (dprintf(tmp_p->fd, "Team %s won.\nEnd of game.\n", \
		team_win->name) < 0)
			return (ERROR);
		delete_player_elem(tmp_p, server);
		remove_client(tmp_p->fd, active_set);
	}
	seg(server, team_win);
	return (SUCCESS);
}

/*!
* @brief propagates win if endgame condition has ben filled
* @param team_win team that won
* @param server struct containing server infos
* @param active_set set of file descriptors for select
* @return int SUCCESS all the time [TU purpose]
*/
int propagate_win(teams_t *team_win, server_t *server, fd_set *active_set)
{
	teams_t *tmp = server->teams;
	players_t *tmp_p;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp_p = tmp->players;
		browse_players_win(tmp_p, team_win, server, active_set);
	}
	return (SUCCESS);
}

/*!
* @brief browse players to validate endgame condition
* @param tmp_p current player list of team
* @param team current team
* @param server struct containing server infos
* @param active_set set of file descriptors for select
* @return int SUCCESS all the time [TU purpose]
*/
int browse_players_endgame(players_t *tmp_p, teams_t *team, server_t *server, \
		fd_set *active_set)
{
	int i = 0;

	for (; tmp_p != NULL; tmp_p = tmp_p->next) {
		if (tmp_p->level == 8)
			i++;
	}
	if (i == 6)
		propagate_win(team, server, active_set);
	return (SUCCESS);
}

/*!
* @brief checks if end game condition is filled
* @param server struct contaning server infos
* @param active_set set of file descriptors for select
* @return int SUCCESS all the time [TU purpose]
*/
int end_game(server_t *server, fd_set *active_set)
{
	teams_t *tmp = server->teams;
	players_t *tmp_p;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp_p = tmp->players;
		browse_players_endgame(tmp_p, tmp, server, active_set);
	}
	return (SUCCESS);
}