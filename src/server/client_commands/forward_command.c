/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** forward command
*/

#include "server.h"

/*!
* @brief updates position according to current direction
* @param player the player to move
* @param server struct containing server infos
*/
void update_pos(players_t *player, server_t *server)
{
	switch (player->direction) {
		case D_UP:
			player->y == 0 ? player->y = (server->y) - 1 :
			player->y--;
			break;
		case D_DOWN:
			player->y == (server->y) - 1 ? player->y = 0 :
			player->y++;
			break;
		case D_LEFT:
			player->x == 0 ? player->x = (server->x) - 1 :
			player->x--;
			break;
		case D_RIGHT:
			player->x == (server->x) - 1 ? player->x = 0 :
			player->x++;
			break;
	}
}

/*!
* @brief allows a player to go forward according to its actual direction
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void forward_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	players_t *tmp;

	(void)action;
	if (player != NULL) {
		tmp = player;
		delete_player_square(player, server);
		update_pos(player, server);
		add_player_square(tmp, server);
		if (dprintf(fd, REPL_OK) < 0)
			exit(ERROR);
	}
	else {
		if (dprintf(fd, REPL_KO) < 0)
			exit(ERROR);
	}
}