/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look additionnal func
*/

#include "server.h"

/*!
* @brief updates y value accrording to direction of player
* @param player current player
* @param y y to update
* @return int new value for y
*/
int update_y(players_t *player, int y)
{
	if (player->direction == D_DOWN || player->direction == D_RIGHT)
			y++;
	else
			y--;
	return (y);
}