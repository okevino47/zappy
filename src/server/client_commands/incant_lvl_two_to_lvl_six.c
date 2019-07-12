/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incant from lvl 2 to lvl 6
*/

#include "server.h"

/*!
* @brief checks necessary ressources and rises a player from lvl 1 to lvl 2
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_two(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);

	if (square->stones->lin >= 1 && square->nb_players == 1) {
		square->stones->lin--;
		player->level++;
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
* @brief checks necessary ressources and rises players from lvl 2 to lvl 3
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_three(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 2 && check_lvl(2, square) && stone->lin >= 1
	&& stone->der >= 1 && stone->sib >= 1) {
		stone->lin--;
		stone->der--;
		stone->sib--;
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
* @brief checks necessary ressources and rises players from lvl 3 to lvl 4
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_four(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 2 && check_lvl(3, square) && stone->lin >= 2
	&& stone->sib >= 1 && stone->phi >= 2) {
		stone->lin -= 2;
		stone->sib--;
		stone->phi -= 2;
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
* @brief checks necessary ressources and rises players from lvl 4 to lvl 5
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_five(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 4 && check_lvl(4, square) && stone->lin >= 1
	&& stone->der >= 1 && stone->sib >= 2 && stone->phi >= 1) {
		stone->lin--;
		stone->sib -= 2;
		stone->phi--;
		stone->der--;
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
* @brief checks necessary ressources and rises players from lvl 5 to lvl 6
* @param player player asking for incantation
* @param server struct containing server infos
*/
void rise_lvl_six(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	stones_t *stone = square->stones;

	if (square->nb_players == 4 && check_lvl(5, square) && stone->lin >= 1
	&& stone->der >= 2 && stone->sib >= 1 && stone->men >= 3) {
		stone->lin--;
		stone->der -= 2;
		stone->sib--;
		stone->men -= 3;
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