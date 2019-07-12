/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fork command
*/

#include "server.h"

/*!
* @brief opens a new slot in team
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void fork_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	teams_t *team;
	eggs_t *egg;

	(void)action;
	if (player != NULL)
		team = get_team_by_player(player, server);
	if (team != NULL) {
		egg = add_elem_egg(team, player);
		enw(server, player, egg);
		if (dprintf(fd, REPL_OK) < 0)
			exit(ERROR);
	}
	else {
		if (dprintf(fd, REPL_KO) < 0)
			exit(ERROR);
	}
}