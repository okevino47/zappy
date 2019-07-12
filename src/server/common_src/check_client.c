/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check client
*/

#include "server.h"

/*!
* @brief add client to its team or setup monitor client
* @param team current team
* @param buf buffer containing team name or MONITOR if graphical client
* @param server struct containing server infos
* @param fd file descriptor of current client
* @return int SUCCESS if client added or FAILURE if not
*/
int add_client_team(teams_t *team, char *buf, server_t *server, int fd)
{
	if (team != NULL && team->nb_players < team->max_players)
		return (add_perm_client(server, fd, team));
	else if (strcmp("MONITOR", buf) == 0 && \
	server->graph->fd == -1)
		return (init_graph_monitor(fd, server));
	return (FAILURE);
}

/*!
* @brief check the client status and moves it to its team if its valid
* @param fd file descriptor of current client
* @param server struct containing server infos
* @return int returns the status of the client
*/
int check_client(int fd, server_t *server)
{
	char *buf = malloc(sizeof(char) * 1024);
	teams_t *team;

	if (client_is_tmp(fd, server)) {
		memset(buf, 0, 1023);
		read(fd, buf, 1023);
		buf[strlen(buf) - 1] = '\0';
		team = get_team_by_name(buf, server);
		if (add_client_team(team, buf, server, fd) == SUCCESS) {
			return (SUCCESS);
		}
		delete_tmp_client(fd, server);
		remove_client(fd, server->active_set);
		dprintf(fd, REPL_KO);
		return (ERROR);
	}
	return (FAILURE);
}