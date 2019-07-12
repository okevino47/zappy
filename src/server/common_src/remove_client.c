/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** remove client
*/

#include "server.h"

/*!
* @brief removes a client from fd set and close its fd
* @param fd file descriptor of current client
* @param active_set set of fd for select
* @return int returns SUCCESS if close successful, ERROR if not
*/
int remove_client(int fd, fd_set *active_set)
{
	FD_CLR(fd, active_set);
	if (close(fd) == -1)
		return (ERROR);
	return (SUCCESS);
}

/*!
* @brief checks if an egg is possible for new player. Player gets the coord of
* egg if egg is disponible and egg is deleted
* @param team current team
* @param player new player
* @return int SUCCESS if an egg was available
*/
int get_possible_egg(teams_t *team, players_t *player, server_t *server)
{
	eggs_t *tmp = team->eggs;

	if (team->eggs == NULL)
		return (FAILURE);
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->ready) {
			ebo(server, tmp);
			player->x = tmp->x;
			player->y = tmp->y;
			delete_egg_elem(team, tmp);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

/*!
* @brief adds a new permanent player
* @param server struct containing server infos
* @param fd file descriptor of current player
* @param team current team
* @return int SUCCESS every time
*/
int add_perm_client(server_t *server, int fd, teams_t *team)
{
	players_t *player = get_valid_player(fd, server);

	team->nb_players += 1;
	delete_tmp_client(fd, server);
	add_elem_player(server, team->name, player);
	get_possible_egg(team, player, server);
	add_player_square(player, server);
	dprintf(fd, "%d\n%d %d\n", team->max_players -
	team->nb_players, player->x, player->y);
	pnw(server, team, player);
	return (SUCCESS);
}

/*!
* @brief handles read return and quitting of a player
* @param read_ret read return
* @param server struct containing server infos
* @param player current player
*/
void handle_read_ret(int read_ret, server_t *server, players_t *player)
{
	if (read_ret < 0)
		exit (ERROR);
	if (read_ret == 0) {
		pdi(server, player);
		remove_client(player->fd, server->active_set);
		delete_player_square(player, server);
		delete_player_elem(player, server);
	}
}