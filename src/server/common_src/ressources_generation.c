/*
** EPITECH PROJECT, 2018
** ressources_generation
** File description:
** ressources_generation.hpp ressources_generation.cpp
*/

#include "server.h"

/*!
* @brief Mother function of the ressources generation
* algorithm, generate random number to maximise
* the random generation of every ressources all
* over the map, square by square based on the
* time.
* @param [in] server
* @param [in] t_act
* @return The map modified by the ressources
* 	  generation.
*/
square_t **random_ressources_generation(const server_t *server)
{
	int line = 0;
	int col = 0;
	int choice = 0;
	square_t **map = server->map;

	generate_random_values(server, &line, &col, &choice);
	if (!map || line > server->y || col > server->x || \
	map[line][col].nb_players != 0)
		return (map);
	if (count_all_ressources(&(map[line][col])) >= 10)
		return (map);
	gen_ressources(&(map[line][col]), choice);
	return (map);
}

/*!
* @brief Count all ressources which are present on
* the square given.
* @param [in] square
* @return the number of ressources found.
*/
int count_all_ressources(const square_t *square)
{
	int result = 0;

	result += square->food;
	result += square->stones->lin;
	result += square->stones->der;
	result += square->stones->men;
	result += square->stones->phi;
	result += square->stones->sib;
	result += square->stones->thy;
	return (result);
}

/*!
* @brief function used to complete gen_ressources function
* @param square current square
* @param choice random number to generate ressources
*/
void last_cases(square_t *square, int choice)
{
	switch (choice) {
		case 4:
			square->stones->men += 2;
			square->stones->phi += 3;
			square->stones->der += 1;
			square->food += 4;
			break;
		case 5:
			square->stones->thy += 1;
			square->food += 2;
			break;
		case 6:
			square->food += 1;
			square->stones->sib += 1;
			break;
	}
}

/*!
* Chose by a random number, what kind of
* ressources will be generate on the square.
* @param [out] square
* @param [in] choice
* @return The square after ressources generation.
*/
int gen_ressources(square_t *square, const int choice)
{
	switch (choice) {
		case 1:
			square->food += 1;
			square->stones->lin += 3;
			break;
		case 2:
			square->food += 2;
			square->stones->der += 1;
			break;
		case 3:
			square->food += 4;
			break;
		default:
			last_cases(square, choice);
			break;
	}
	return (SUCCESS);
}

/*!
* Generate the most random value as posible for
* the 3 ints given in parameter.
* @param [in] server
* @param [out] line
* @param [out] col
* @param [out] choice
* @return Always SUCCESS code
*	  TUs purpose
*/
int	generate_random_values(const server_t *server, int *line, \
	int *col, int *choice)
{
	(*col) = 0 + rand() % (server->x - 0);
	(*line) = 0 + rand() % (server->y - 0);
	(*choice) = 1 + rand() % (6 - 0);
	return (SUCCESS);
}