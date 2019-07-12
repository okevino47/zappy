/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle params
*/

#include "server.h"

/*!
* @brief checks if a str contains only numbers
* @param str the str to check
* @return true if there are only numbers in the string
* @return false if there is a charac different than a number in the string
*/
bool isnum(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

/*!
* @brief checks if the params are valid
* @param av the array containing all params
* @param ac the number of params
*/
int handle_params(char **av, int ac)
{
	if (ac < 13) {
		fprintf(stderr, "No enough arguments.\n");
		exit(ERROR);
	}
	if (strcmp("-p", av[1]) != 0 || strcmp("-x", av[3]) != 0 || \
	strcmp("-y", av[5]) != 0 || strcmp("-n", av[7]) != 0 || \
	strcmp("-c", av[ac - 4]) != 0 || strcmp("-f", av[ac - 2]) != 0) {
		fprintf(stderr, "Bad flag(s).\n");
		exit(ERROR);
	}
	if (!isnum(av[2]) || !isnum(av[4]) || !isnum(av[6]) || \
	!isnum(av[ac - 1]) || !isnum(av[ac - 3]) || atoi(av[4]) <= 0 || \
	atoi(av[6]) <= 0) {
		fprintf(stderr, "Bad argument(s).\n");
		exit(ERROR);
	}
	return (SUCCESS);
}