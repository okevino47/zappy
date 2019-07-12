/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** left command
*/

#include "server.h"

/*!
* @brief make the current player turn to its left
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void left_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);

	(void)action;
	if (player != NULL) {
		if (player->direction == D_UP)
			player->direction = D_LEFT;
		else
			player->direction--;
		if (dprintf(fd, REPL_OK) < 0)
			exit(ERROR);
	}
	else {
		if (dprintf(fd, REPL_KO) < 0)
			exit(ERROR);
	}
}