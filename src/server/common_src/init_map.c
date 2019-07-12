/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init map
*/

#include "server.h"

/*!
* @brief init the values of map struct
* @return square_t *a pointer to the initialized struct
*/
square_t **init_map(int x, int y)
{
	square_t **map;

	map = malloc(sizeof(square_t *) * y);
	if (map == NULL)
		exit(ERROR);
	for (int i = 0; i < y; i++) {
		map[i] = malloc(sizeof(square_t) * x);
		for (int j = 0; j < x; j++)
			init_square_struct(&map[i][j]);
	}
	return (map);
}