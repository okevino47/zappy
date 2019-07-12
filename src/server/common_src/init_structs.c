/*
** EPITECH PROJECT, 2018
** irc
** File description:
** init structs
*/

#include "server.h"

/*!
* @brief init the values of square struct
* @param pointer to the struct to init
* @return Always "SUCCESS" code
* 	  TUs purpose
*/
void init_square_struct(square_t *square)
{
	init_stones_struct(&(square->stones));
	square->nb_players = 0;
	square->food = 0;
	square->players = NULL;
}

/*!
* @brief init the values of teams struct
* @param team a pointer to the struct to initialize
*/
teams_t *init_teams_struct(char *name, int max_players)
{
	teams_t *team = malloc(sizeof(teams_t));

	if (team == NULL)
		exit(ERROR);
	team->name = name;
	team->nb_players = 0;
	team->max_players = max_players;
	team->players = NULL;
	team->eggs = NULL;
	team->next = NULL;
	return (team);
}

/*!
* @brief init the values of server struct
* @return server_t * a pointer to the initialized struct
*/
server_t *init_server_struct(int fd, int freq, int x, int y)
{
	server_t *server = malloc(sizeof(server_t));

	if (server == NULL)
		exit(ERROR);
	server->fd = fd;
	server->graph = init_graph_struct();
	server->freq = freq;
	server->x = x;
	server->y = y;
	server->map = init_map(x, y);
	server->teams = NULL;
	server->tmp_client = NULL;
	return (server);
}


/*!
* @brief Initatilise a "stone" structure by setting all the values at '0'.
* @param pointer to struct to be initialized
*/
void init_stones_struct(stones_t **stone)
{
	(*stone) = malloc(sizeof(stones_t));

	if (!(*stone))
		exit(ERROR);
	(*stone)->lin = 0;
	(*stone)->der = 0;
	(*stone)->sib = 0;
	(*stone)->men = 0;
	(*stone)->phi = 0;
	(*stone)->thy = 0;
}

/*!
* @bried Initialise the player structure by assigning the
* fd given in paramater and by giving the maximum
* life possible with the stone struct.
* @param [in] fd
* @param player pointer to the struct to initialize
*/
players_t *init_player_struct(int fd, server_t *server)
{
	players_t *player = malloc(sizeof(players_t));

	if (!player)
		exit(ERROR);
	player->fd = fd;
	player->x = rand() % server->x;
	player->y = rand() % server->y;
	player->life = 1260;
	player->food = 10;
	init_stones_struct(&(player->stones));
	player->level = 1;
	player->actions = NULL;
	player->direction = D_UP;
	player->cbuff = init_cbuff_struct();
	player->next = NULL;
	return (player);
}