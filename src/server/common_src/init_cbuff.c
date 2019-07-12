/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init cbuff
*/

#include "server.h"

/*!
* @brief inits the cbuff struct
* @return cbuff_t *a pointer to the initialized struct
*/
cbuff_t *init_cbuff_struct(void)
{
	cbuff_t *buf = malloc(sizeof(cbuff_t));

	if (buf == NULL)
		exit(ERROR);
	buf->buffer = malloc(sizeof(char) * 4096);
	if (buf->buffer == NULL)
		exit(ERROR);
	buf->read_on = 0;
	buf->write_on = 0;
	return (buf);
}