/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look command
*/

#include "server.h"

/*!
* @brief prints number of elements for a stone
* @param stone stone to count elements
* @param fd file descriptor of current client
* @param stone_name name of stone
*/
void print_stone(int stone, int fd, char *stone_name)
{
	for (int i = 0; i < stone; i++) {
		dprintf(fd, "%s ", stone_name);
	}
}

/*!
* @brief prints all stones actually on square
* @param fd file descriptor of current player
* @param stone struct containing all stones infos
*/
void print_all_stones(int fd, stones_t *stone)
{
	print_stone(stone->der, fd, "deraumere");
	print_stone(stone->lin, fd, "linemate");
	print_stone(stone->sib, fd, "sibur");
	print_stone(stone->men, fd, "mendiane");
	print_stone(stone->phi, fd, "phiras");
	print_stone(stone->thy, fd, "thystame");
}

/*!
* @brief prints ressources on a square
* @param x coord x of square
* @param y coord y of square
* @param server struct containing server infos
* @param fd file descriptor of current client
*/
void print_square_ressources(int x, int y, server_t *server, int fd)
{
	square_t *square = &(server->map[y][x]);

	for (int i = 0; i < square->nb_players; i++)
		dprintf(fd, "player ");
	for (int i = 0; i < square->food; i++)
		dprintf(fd, "food ");
	print_all_stones(fd, square->stones);
}

/*!
* @brief gets coord with principe of circular map
* @param x coord x
* @param y coord y
* @param server struct containing server infos
* @param fd file descriptor of current player
*/
void get_coord(int x, int y, server_t *server, int fd)
{
	players_t *player = get_current_player(fd, server);

	if (x >= 0)
		x = x % (server->x);
	else if (ABS(x) == server->x)
		x = 0;
	else
		x = server->x + (ABS(x) % server->x * -1);
	if (y >= 0)
		y = y % (server->y);
	else if (ABS(y) == server->y)
		y = 0;
	else
		y = server->y + (ABS(y) % server->y * -1);
	if (!(x == player->x && y == player->y))
		dprintf(fd, ",");
	print_square_ressources(x, y, server, fd);
}

/*!
* @brief prints what's in vision field of player according to its lvl
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void look_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	int x;
	int y;

	(void)action;
	(player->direction == D_UP || player->direction == D_DOWN) ?
	(x = player->x) : (x = player->y);
	(player->direction == D_UP || player->direction == D_DOWN) ?
	(y = player->y) : (y = player->x);
	dprintf(fd, "[ ");
	for (int i = 0; i <= player->level; i++) {
		for (int j = x - i; j <= x + i; j++)
			(player->direction == D_UP || \
			player->direction == D_DOWN ?
			get_coord(j, y, server, fd) :
			get_coord(y, j, server, fd));
		y = update_y(player, y);
	}
	dprintf(fd, "]\n");
}