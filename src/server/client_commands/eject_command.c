/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject command
*/

#include "server.h"

/*!
* Mother function of "eject_command" which retrieve the
* current player ejecting the others, choosing the next
* ejecting destination square and then pushing everyone
* to this square.
* @param [in/out] server
* @param [n/a] action
* @param [in] fd
*/
void eject_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	node_player_t *ej_list[server->map[player->y][player->x].nb_players];
	int line;
	int col;

	(void)action;
	if (player == NULL)
		if (dprintf(fd, REPL_KO) < 0)
			exit(ERROR);
	line = player->y;
	col = player->x;
	choose_eject_square_coord(&line, &col, player, server);
	fill_eject_list(ej_list, player, (const square_t **) server->map);
	eject_every_player(line, col, ej_list, server);
	pex(server, player);
	if (dprintf(fd, REPL_OK) < 0)
		exit(ERROR);
}

/*!
* @brief Fill the list created which list every player that
* 	  we have to eject to the next square.
* @param [out] list
* @param [in] player
* @param [in] map
* @return return "SUCCESS" code in every case
* 	  [ TUs purpose ]
*/
int	fill_eject_list(node_player_t **list, const players_t *player, \
	const square_t **map)
{
	square_t *square = (square_t *) &(map[player->y][player->x]);
	node_player_t *present = square->players;
	int i = 0;

	while (present) {
		if (present->player != player) {
			list[i] = present;
			i++;
		}
		present = present->next;
	}
	list[i] = NULL;
	return (SUCCESS);
}

/*!
* Choose the particulars of the square where others
* will be ejected.
* @param [out] line
* @param [out] col
* @param [in] player
* @param [in] server
* @return "SUCCESS" code in every case
* 	[TUs purpose]
*/
int	choose_eject_square_coord(int *line, int *col, \
	const players_t *player, const server_t *server)
{
	switch (player->direction) {
		case D_DOWN:
			(*line) = (player->y == server->y - 1 ? 0 : \
			player->y + 1);
			break;
		case D_UP:
			(*line) = (player->y == 0 ? server->y - 1 : \
			player->y - 1);
			break;
		case D_LEFT:
			(*col) = player->x == 0 ? server->x - 1 : \
			player->x - 1;
			break;
		case D_RIGHT:
			(*col) = (player->x == server->x - 1 ? 0 : \
			player->x + 1);
			break;
	}
	return (SUCCESS);
}

/*!
* Call a loop on every player actually present
* on the square to remove and add them correctly
* on the squares.
* @param [in] line
* @param [in] col
* @param [in/out] list
* @param [in/out] server
* @return "SUCCESS" code in every case
* 	[TUs purpose]
*/
int	eject_every_player(const int line, const int col, \
	node_player_t **list, server_t *server)
{
	while (*list) {
		delete_player_square((*list)->player, server);
		(*list)->player->x = col;
		(*list)->player->y = line;
		add_player_square((*list)->player, server);
		list += 1;
	}
	return (SUCCESS);
}
