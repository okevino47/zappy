/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** right command
*/

#include "server.h"

/*!
* @brief make the current player turn to its right
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void right_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);

	(void)action;
	if (player != NULL) {
		if (player->direction == D_LEFT)
			player->direction = D_UP;
		else
			player->direction++;
		if (dprintf(fd, REPL_OK) < 0)
			exit(84);
	}
	else {
		if (dprintf(fd, REPL_KO) < 0)
			exit(ERROR);
	}
}