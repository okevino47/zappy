/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incant from lvl 7 to lvl 8
*/

#include "server.h"

/*!
* @brief updates stones value on current square for an incantation
*from lvl 7 to lvl 8
* @param stone all stones to modify
*/
void update_stones_lvl_eight(stones_t *stone)
{
	stone->lin -= 2;
	stone->der -= 2;
	stone->sib -= 2;
	stone->men -= 2;
	stone->phi -= 2;
	stone->thy--;
}

/*!
* @brief checks necessary ressources and rises players from lvl 6 to lvl 7
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_seven(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 6 && check_lvl(6, square) && stone->lin >= 1
	&& stone->der >= 2 && stone->sib >= 3 && stone->phi >= 1) {
		stone->lin--;
		stone->der -= 2;
		stone->sib -= 3;
		stone->phi--;
		update_lvl(square);
		pie_success(server, player);
		if (end_elevation_propagate(server, player) == ERROR)
			exit(ERROR);
	}
	else {
		pie_failure(server, player);
		if (fail_elevation_propagate(server, player) == ERROR)
			exit(ERROR);
	}
}

/*!
* @brief checks necessary ressources and rises players from lvl 7 to lvl 8
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_eight(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 6 && check_lvl(7, square) && stone->lin >= 2
	&& stone->der >= 2 && stone->sib >= 2 && stone->men >= 2 && \
	stone->phi >= 2 && stone->thy >= 1) {
		update_stones_lvl_eight(stone);
		update_lvl(square);
		pie_success(server, player);
		if (end_elevation_propagate(server, player) == ERROR)
			exit(ERROR);
	}
	else {
		pie_failure(server, player);
		if (fail_elevation_propagate(server, player) == ERROR)
			exit(ERROR);
	}
}