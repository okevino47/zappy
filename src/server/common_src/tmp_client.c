/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** tmp client
*/

#include "server.h"

/*!
* @brief checks if client is in client_tmp list
* @param fd fd of client to check
* @param server struct containing server infos
* @return true if client is in tmp_list
* @return false if client is not in tmp list
*/
bool client_is_tmp(int fd, server_t *server)
{
	players_t *tmp = server->tmp_client;

	if (tmp == NULL)
		return (false);
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->fd == fd)
			return (true);
	}
	return (false);
}

/*!
* @brief adds a client to the tmp client list
* @param fd file descriptor of current client
* @param server struct containing server infos
*/
void add_tmp_client(int fd, server_t *server)
{
	players_t *tmp = server->tmp_client;
	players_t *new_player = init_player_struct(fd, server);

	dprintf(fd, "WELCOME\n");
	if (server->tmp_client == NULL) {
		server->tmp_client = new_player;
	}
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = new_player;
	}
}

/*!
* @brief gets a player by its file descriptor
* @param fd file descriptor of current client
* @param server struct containing server infos
* @return players_t * a pointer to the client if found, NULL if not
*/
players_t *get_valid_player(int fd, server_t *server)
{
	players_t *tmp = server->tmp_client;

	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->fd == fd)
			return (tmp);
	}
	return (NULL);
}

/*!
* @brief deletes a client from tmp client list
* @param fd file descriptor of current client
* @param server struct containing server infos
*/
int delete_tmp_client(int fd, server_t *server)
{
	players_t *tmp = server->tmp_client;
	players_t *previous = server->tmp_client;

	if (fd == server->tmp_client->fd)
		server->tmp_client = tmp->next;
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->fd == fd) {
			previous->next = tmp->next;
			tmp->next = NULL;
			break;
		}
		previous = tmp;
	}
	return (SUCCESS);
}