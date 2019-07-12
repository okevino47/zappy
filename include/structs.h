/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** structs
*/

#ifndef STRUCTS_H_
	#define STRUCTS_H_

#include "server.h"


/*!
* @brief regroups all infos about eggs
*/
typedef struct eggs_s {
	int id;
	int x;
	int y;
	int time;
	bool ready;
	struct eggs_s *next;
}		eggs_t;

/*!
* @brief regroups all infos about circular buffer
*/
typedef struct cbuff_s {
	char *buffer;
	size_t read_on;
	size_t write_on;
}		cbuff_t;

/*!
* @brief regroups all the actions informations
*/
typedef struct actions_s {
	enum e_actions action;
	int cycles;
	int max_cycles;
	char **tab;
	struct actions_s *next;
}	actions_t;

/*!
* @brief regroups all the existing stones
*/
typedef struct stones_s {
	int lin;
	int der;
	int sib;
	int men;
	int phi;
	int thy;
}	stones_t;

/*!
* @brief all informations about player
*/
typedef struct players_s {
	int fd;
	int x;
	int y;
	stones_t *stones;
	int life;
	int food;
	int level;
	actions_t *actions;
	cbuff_t *cbuff;
	e_direction direction;
	struct players_s *next;
}	players_t;

typedef struct node_player_s {
	players_t *player;
	struct node_player_s *next;
}		node_player_t;

/*!
* @brief all informations about the actual square on the map
*/
typedef struct square_s {
	stones_t *stones;
	int nb_players;
	int food;
	node_player_t *players;
}	square_t;

/*!
* @brief all informations about teams
*/
typedef struct teams_s {
	char *name;
	int nb_players;
	int max_players;
	players_t *players;
	eggs_t *eggs;
	struct teams_s *next;
}	teams_t;

/*!
* @brief containing graphical monitor informations
*/
typedef struct graph_s {
	int fd;
	cbuff_t *cbuff;
}		graph_t;

/*!
* @brief all server informations
*/
typedef struct server_s {
	int fd;
	graph_t *graph;
	fd_set *active_set;
	int freq;
	int x;
	int y;
	square_t **map;
	teams_t *teams;
	players_t *tmp_client;
}	server_t;

#endif /* !STRUCTS_H_ */
