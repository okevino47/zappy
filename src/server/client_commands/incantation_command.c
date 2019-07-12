/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incantation command
*/

#include "server.h"

/*!
* @brief checks if all players on square have the good lvl for incantation
* @param lvl lvl asked
* @param square current square
* @return true if all players have the good lvl
* @return false if not all players have the good lvl
*/
bool check_lvl(int lvl, square_t *square)
{
	node_player_t *tmp = square->players;

	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->player->level != lvl)
			return (false);
	}
	return (true);
}

/*!
* @brief updates lvl of all players on current square
* @param square current square
*/
void update_lvl(square_t *square)
{
	node_player_t *tmp = square->players;

	for (; tmp != NULL; tmp = tmp->next)
		tmp->player->level++;
}

/*!
* @brief calls corresponding function for lvl rise from lvl 5 to lvl 7
* @param player player asking for incantation
* @param server struct containing server infos
*/
void other_levels(players_t *player, server_t *server)
{
	switch (player->level) {
		case 5:
			rise_lvl_six(player, server);
			break;
		case 6:
			rise_lvl_seven(player, server);
			break;
		case 7:
			rise_lvl_eight(player, server);
			break;
		default:
			dprintf(player->fd, REPL_KO);
			break;
	}
}

/*!
* @brief allow a player to make an incantation to lvl up according to its lvl
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void incantation_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);

	(void)action;
	switch (player->level) {
		case 1:
			rise_lvl_two(player, server);
			break;
		case 2:
			rise_lvl_three(player, server);
			break;
		case 3:
			rise_lvl_four(player, server);
			break;
		case 4:
			rise_lvl_five(player, server);
			break;
		default:
			other_levels(player, server);
			break;
	}
}