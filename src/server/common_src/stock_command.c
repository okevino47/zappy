/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** get current player
*/

#include "server.h"
/*!
* @brief get command id according to macros
* @param tab tab containing all arguments of action
* @param tab_macros array of macros
* @return int the command id accroding to macros
*/
int get_command_id(char **tab, char **tab_macros)
{
	int i = 0;

	for (; tab_macros[i] != NULL; i++) {
		if (strcmp(tab_macros[i], tab[0]) == 0)
			return (i);
	}
	return (FAILURE);
}

/*!
* @brief check number of arguments in tab
* @param id id of command
* @param tab tab containing arguments of action
* @return int FAILURE if nb of args is not valid and SUCESS if valid
*/
int check_nb_args(int id, char **tab)
{
	if (id == BROAD || id == TAKE || id == SET) {
		if (tab_size(tab) != 2)
			return (FAILURE);
	}
	else {
		if (tab_size(tab) != 1)
			return (FAILURE);
	}
	return (SUCCESS);
}

/*!
* @brief stocks actions of client
* @param command the command to parse
* @param fd file descriptor of current client
* @param server struct containing server infos
*/
void stock_command(char *command, int fd, server_t *server)
{
	char **tab = str_to_word_array(command);
	char **tab_macros = command_array();
	int command_id = get_command_id(tab, tab_macros);
	players_t *player = get_current_player(fd, server);

	if (command_id == FAILURE || check_nb_args(command_id, tab) == FAILURE)
		dprintf(fd, REPL_KO);
	else if (command_id == CONN_NBR)
		connect_nbr_command(server, NULL, fd);
	else
		create_action_elem(command_id, player, tab, server);
}