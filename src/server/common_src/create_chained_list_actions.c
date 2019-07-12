/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** create chained list actions
*/

#include "server.h"

/*!
* @brief inits action structure
* @param tab tab containing command args
* @param cycles max cycles of action
* @return actions_t *pointer to action struct
*/
actions_t *init_struct_action(char **tab, int cycles, int id)
{
	actions_t *action = malloc(sizeof(actions_t));

	if (action == NULL)
		exit(ERROR);
	action->action = id;
	action->cycles = 0;
	action->max_cycles = cycles;
	action->tab = tab;
	action->next = NULL;
	return (action);
}

/*!
* @brief add element to action chained list
* @param player current player
* @param tab tab containing action arguments
* @param cycles number of cycles max for the action
*/
void add_elem_action(players_t *player, char **tab, int cycles, int id)
{
	actions_t *tmp = player->actions;

	if (player->actions == NULL)
		player->actions = init_struct_action(tab, cycles, id);
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = init_struct_action(tab, cycles, id);
	}
}

/*!
* @brief add and elem to actions chained list according to the cycle time
* @param command_id the command id according to macros
* @param player pointer to current player
* @param tab tab containing all actiona arguments
*/
void create_action_elem(int command_id, players_t *player, char **tab, \
server_t *server)
{
	if (command_id == INVENTORY)
		add_elem_action(player, tab, 1, command_id);
	else if (command_id >= FWD && command_id <= SET)
		add_elem_action(player, tab, 7, command_id);
	else {
		if (command_id == FORK) {
			pfk(server, player);
			add_elem_action(player, tab, 42, command_id);
		}
		else if (command_id == INCANT) {
			pic(server, player);
			elevation_underway_propagate(server, player);
			add_elem_action(player, tab, 300, command_id);
		}
	}
}

/*!
* @brief deletes an action element from current client action chained list
* @param action the action elem to remove
* @param player the current client
*/
void delete_action_elem(actions_t *action, players_t *player)
{
	actions_t *tmp = player->actions;
	actions_t *prev = NULL;

	if (tmp == action) {
		player->actions = tmp->next;
		tmp = player->actions;
	}
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp == action) {
			prev->next = tmp->next;
			free(tmp);
			break;
		}
		prev = tmp;
	}
}