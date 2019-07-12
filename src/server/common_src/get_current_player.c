/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** get current player
*/

#include "server.h"

/*!
* Loop in the team given in parameter to find the player.
* @param [in] fd
* @param [in/out] player
* @return The pointer to the player if is was found or
* 	   "NULL" in other case.
*/
players_t *check_if_player_is_in_team(const int fd, players_t *player)
{
	for (; player != NULL; player = player->next) {
		if (fd == player->fd)
			return (player);
	}
	return (NULL);
}

/*!
* Try to find a specific player in all the teams
* by checking the fd given in parameter.
* @param [in] fd
* @param [in] server
* @return "NULL" if the player is not found ortherwise
* 	   return a the player found.
*/
players_t *get_current_player(const int fd, const server_t *server)
{
	teams_t *tmp = server->teams;
	players_t *play_tmp;
	players_t *result;

	for (; tmp != NULL; tmp = tmp->next) {
		play_tmp = tmp->players;
		result = check_if_player_is_in_team(fd, play_tmp);
		if (result != NULL)
			return (result);
	}
	return (NULL);
}