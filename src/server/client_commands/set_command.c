/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** set command
*/

#include "server.h"

/*!
* @brief checks if ressources can be setted
* @param i id of stone
* @param square current square
* @param player current player
* @return int SUCCESS if ressource can be set, FAILURE if not
*/
int handle_other_ressources_set(int i, square_t *square, players_t *player)
{
	if (i == 3 && player->stones->men > 0) {

			square->stones->men++;
			player->stones->men--;
			return (SUCCESS);
	}
	else if (i == 4 && player->stones->phi > 0) {
		square->stones->phi++;
		player->stones->phi--;
		return (SUCCESS);
	}
	else {
		if (i == 5 && player->stones->thy > 0) {

			square->stones->thy++;
			player->stones->thy--;
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

/*!
* @brief checks if ressources can be setted
* @param i id of stone
* @param square current square
* @param player current player
* @return int SUCCESS if ressource can be set, FAILURE if not
*/
int handle_ressources_set(int i, square_t *square, players_t *player)
{
	if (i == 0 && player->stones->lin > 0) {
		square->stones->lin++;
		player->stones->lin--;
		return (SUCCESS);
	}
	else if (i == 1 && player->stones->der > 0) {
		square->stones->der++;
		player->stones->der--;
		return (SUCCESS);
	}
	else {
		if (i == 2 && player->stones->sib > 0) {

			square->stones->sib++;
			player->stones->sib--;
			return (SUCCESS);
		}
	}
	return (handle_other_ressources_set(i, square, player));
}

/*!
* @brief browse all stones and checks if its corresponding to stone to set
* @param action array of strings ontaining args of action
* @param square current square
* @param player current player
* @return int FAILURE if not possible to set stone, SUCCESS if possible
*/
int browse_stones_set(actions_t *action, square_t *square, players_t *player, \
	server_t *server)
{
	char **tab_stones = name_stones_array();

	for (int i = 0; tab_stones[i] != NULL; i++) {
		if (strcmp(tab_stones[i], action->tab[1]) == 0) {
			pdr(server, player, i + 1);
			return (handle_ressources_set(i, square, player));
		}
	}
	return (FAILURE);
}

/*!
* @brief sets an object from player inventory to current square
* @param server struct containing server infos
* @param action current action element
* @param fd file descriptor of current client
*/
void set_command(server_t *server, actions_t *action, int fd)
{
	players_t *player = get_current_player(fd, server);
	square_t *square = &(server->map[player->y][player->x]);

	if (strcmp("food", action->tab[1]) == 0 && player->food > 0) {
		square->food++;
		player->food--;
		pdr(server, player, 0);
		dprintf(fd, REPL_OK);
	}
	else if (browse_stones_set(action, square, player, server) == SUCCESS)
		dprintf(fd, REPL_OK);
	else
		dprintf(fd, REPL_KO);
}