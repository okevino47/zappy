/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** create chained list node
*/

#include "server.h"

/*!
* @brief inits node struct
* @param player player to put in node
* @return node_player_t * initialized struct
*/
node_player_t *init_node_struct(players_t *player)
{
	node_player_t *node = malloc(sizeof(node_player_t));

	if (node == NULL)
		exit(ERROR);
	node->player = player;
	node->next = NULL;
	return (node);
}

/*!
* @brief adds a player to a square
* @param player player to add
* @param server struct containing server infos
*/
void add_player_square(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	node_player_t *tmp = square->players;

	if (square->players == NULL)
		square->players = init_node_struct(player);
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = init_node_struct(player);
	}
	square->nb_players++;
}

/*!
* @brief deletes a player from a square
* @param player current player
* @param server struct containing server infos
*/
void delete_player_square(players_t *player, server_t *server)
{
	square_t *square = &(server->map[player->y][player->x]);
	node_player_t *tmp = square->players;
	node_player_t *prev = square->players;

	if (tmp->player == player) {
		square->players = tmp;
		tmp = square->players;
	}
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->player == player) {
			prev->next = tmp->next;
			tmp->next = NULL;
			break;
		}
		prev = tmp;
	}
	if (square->nb_players > 0)
		square->nb_players--;
}
