/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** connect_nbr command
*/

#include "server.h"

/*!
* @brief gets a team by a player
* @param player current player
* @param server struct containing server infos
* @return teams_t * pointer to found team or NULL if not found
*/
teams_t *get_team_by_player(players_t *player, server_t *server)
{
	teams_t *tmp = server->teams;
	players_t *tmp_p;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp_p = tmp->players;
		if (check_if_player_is_in_team(player->fd, tmp_p) != NULL)
			return (tmp);
	}
	return (NULL);
}

/*!
* @brief prints the remaining slots for players in team of current player
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void connect_nbr_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	teams_t *team = get_team_by_player(player, server);
	int nb;

	(void)action;
	if (team != NULL) {
		nb = team->max_players - team->nb_players;
		if (dprintf(fd, "%d\n", nb) < 0)
			exit(ERROR);
	}
}