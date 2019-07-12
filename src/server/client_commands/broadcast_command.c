/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast command
*/

#include "server.h"

/*!
* @brief prints the message on file descriptor of receiver
* @param receive_fd file descriptor of receiver
* @param sender_fd file descriptor of sender
* @param name name of team of sender
* @param mess message to be sent
*/
void print_message(int receive_fd, int sender_fd, char *mess, server_t *server)
{
	players_t *receiver = get_current_player(receive_fd, server);
	players_t *sender = get_current_player(sender_fd, server);
	int broad_nb = get_broadcast_nb(receiver, sender);

	if (receive_fd != sender_fd) {
		if (dprintf(receive_fd, REPL_BROAD, broad_nb, mess) < 0)
			exit(ERROR);
	}
}

/*!
* @brief browses teams and players to propagate message
* @param player current player
* @param team team of current player
* @param server struct containing server infos
* @param mess tje message to be sent
*/
void propagate_message(players_t *player, server_t * server, \
		char *mess)
{
	teams_t *tmp = server->teams;
	players_t *tmp_p;

	for (; tmp != NULL; tmp = tmp->next) {
		tmp_p = tmp->players;
		for (; tmp_p != NULL; tmp_p = tmp_p->next)
			print_message(tmp_p->fd, player->fd, mess, server);
	}
}
/*!
* @brief broadcasts a message to all clients actually connected to server
* @param server struct containing server infos
* @param action action element of current action
* @param fd file descriptor of current client
*/
void broadcast_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	teams_t *team = get_team_by_player(player, server);

	if (player != NULL && team != NULL) {
		propagate_message(player, server, action->tab[1]);
		pbc(server, player, action->tab[1]);
		if (dprintf(fd, REPL_OK) < 0)
			exit(ERROR);
	}
}