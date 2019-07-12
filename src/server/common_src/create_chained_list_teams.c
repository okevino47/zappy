/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** create chained list
*/

#include "server.h"

/*!
* @brief get the nb of teams
* @param av array containing all program arguments
* @param i rank to begin the for
* @return int the number of teams
*/
int get_nb_teams(char **av, int i)
{
	int j = 0;
	for (; strcmp(av[i], "-c") != 0; i++)
		j++;
	return (j);
}

/*!
* @brief creates an array of strings containing all teams names
* @param av array containing all program arguments
* @return char ** the array containing all teams names
*/
char **create_teams_tab(char **av)
{
	int i = 0;
	int j = 0;
	char **tab = NULL;
	int nb_teams;

	for (; strcmp("-n", av[i]) != 0; i++);
	i++;
	nb_teams = get_nb_teams(av, i);
	tab = malloc(sizeof(char *) * (nb_teams + 1));
	for (; strcmp("-c", av[i]) != 0; i++) {
		tab[j] = calloc(strlen(av[i]) + 1, sizeof(char));
		strcpy(tab[j], av[i]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

/*!
* @brief inits the teams chained list
* @param server struct conaining all server infos
* @param av array containing all program parameters
*/
void init_teams_list(server_t *server, char **av)
{
	char **tab = create_teams_tab(av);
	int j = 0;
	teams_t *tmp;

	for (; strcmp(av[j], "-c") != 0; j++);
	for (int i = 0; tab[i] != NULL; i++) {
		tmp = server->teams;
		if (server->teams == NULL)
			server->teams = init_teams_struct(tab[i], \
			atoi(av[j + 1]));
		else {
			for (; tmp->next != NULL; tmp = tmp->next);
			tmp->next = init_teams_struct(tab[i], atoi(av[j + 1]));
		}
	}
}