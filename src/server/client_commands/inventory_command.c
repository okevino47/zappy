/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inventory command
*/

#include "server.h"

/*!
* @brief prints inventory of current client on client fd
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void inventory_command(server_t *server, actions_t *action, int fd)
{
	players_t *p = get_current_player(fd, server);
	stones_t *s = p->stones;

	(void)action;
	if (p != NULL)
		dprintf(fd, REPL_INVENTORY, p->food, s->lin, s->der, s->sib, \
		s->men, s->phi, s->thy);
}