/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eggs chained list
*/

#include "server.h"


/*!
* @brief inits all elements of egg struct
* @return eggs_t * initialized egg struct
*/
eggs_t *init_eggs_struct(players_t *player, int id)
{
	eggs_t *egg = malloc(sizeof(eggs_t));

	if (egg == NULL)
		exit(ERROR);
	egg->id = id;
	egg->x = player->x;
	egg->y = player->y;
	egg->time = 0;
	egg->ready = false;
	egg->next = NULL;
	return (egg);
}

/*!
* @brief add element to eggs chained list
* @param team current team
* @param server struct containing server infos
* @param player player the layed the egg
*/
eggs_t *add_elem_egg(teams_t *team, players_t *player)
{
	eggs_t *tmp = team->eggs;
	int i = 0;

	if (team->eggs == NULL) {
		team->eggs = init_eggs_struct(player, 1);
		return (team->eggs);
	}
	for (; tmp->next != NULL; tmp = tmp->next)
		i++;
	tmp->next = init_eggs_struct(player, i + 1);
	return (tmp->next);
}

/*!
* @brief deletes an egg element from current teams eggs chained list
* @param team the team to remove the egg from
*/
void delete_egg_elem(teams_t *team, eggs_t *egg)
{
	eggs_t *tmp = team->eggs;
	eggs_t *previous = NULL;

	if (tmp == egg) {
		team->eggs = tmp->next;
		tmp = team->eggs;
	}
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp == egg) {
			previous->next = tmp->next;
			free(tmp);
			break;
		}
		previous = tmp;
	}
}