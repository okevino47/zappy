/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** create chained list players
*/

#include "server.h"

/*!
* @brief get the pointer of the team having this name
* @param name the name of the researched team
* @param server struct containing all server infos
* @return teams_t * a pointer to the team found or NULL
*/
teams_t *get_team_by_name(char *name, server_t *server)
{
	teams_t *tmp = server->teams;

	for (; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->name, name) == 0)
			return (tmp);
	}
	return (NULL);
}

/*!
* @brief add a player to a team
* @param team the team to add the player
* @param player the player to add to the team
*/
void add_player(teams_t *team, players_t *player)
{
	players_t *tmp = team->players;

	player->next = NULL;
	if (team->players == NULL)
		team->players = player;
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = player;
	}
}

/*!
* @brief add player if team exists
* @param server struct containing server infos
* @param name name of team
* @param player pointer to player
*/
void add_elem_player(server_t *server, char *name, players_t *player)
{
	teams_t *team = get_team_by_name(name, server);

	if (team != NULL) {
		add_player(team, player);
	}
}

/*!
* @brief deletes a player elem from a team
* @param player player to delete
* @param server struct containing server infos
*/
void delete_player_elem(players_t *player, server_t *server)
{
	teams_t *team = get_team_by_player(player, server);
	players_t *tmp = team->players;
	players_t *prev = team->players;

	if (tmp == player) {
		team->players = tmp->next;
		free(tmp);
		tmp = team->players;
	}
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp == player) {
			prev->next = tmp->next;
			free(tmp);
			break;
		}
		prev = tmp;
	}
	if (team->nb_players > 0)
		team->nb_players--;
}