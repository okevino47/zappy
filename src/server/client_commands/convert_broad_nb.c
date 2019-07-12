/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** convert broad nb
*/

#include "server.h"

/*!
* @brief converts broad nb if player direction is right
* @param broad_nb number to convert
* @return int converted direction
*/
int convert_right(int broad_nb)
{
	if (broad_nb + 2 <= 8)
		return (broad_nb + 2);
	return (broad_nb - 6);
}

/*!
* @brief converts broad nb if player direction is down
* @param broad_nb number to convert
* @return int converted direction
*/
int convert_down(int broad_nb)
{
	if (broad_nb + 4 <= 8)
		return (broad_nb + 4);
	return (broad_nb - 4);
}

/*!
* @brief converts broad nb if player direction is left
* @param broad_nb number to convert
* @return int converted direction
*/
int convert_left(int broad_nb)
{
	if (broad_nb + 6 <= 8)
		return (broad_nb + 6);
	return (broad_nb - 2);
}

/*!
* @brief computes broad nb in particular case where x of receiver and sender
* are the same
* @param receiver player receiver of sound
* @param sender player sender of sound
* @return int direction where the sound comes from
*/
int x_equals_broad(players_t *receiver, players_t *sender)
{
	if (receiver->x == sender->x && receiver->y > sender->y)
		return (1);
	else if (receiver->x == sender->x && receiver->y < sender->y)
		return (5);
	return (0);
}

/*!
* @brief computes broad nb in particular case where y of receiver and sender
* are the same
* @param receiver player receiver of sound
* @param sender player sender of sound
* @return int direction where the sound comes from
*/
int y_equals_broad(players_t *receiver, players_t *sender)
{
	if (receiver->x < sender->x && receiver->y == sender->y)
		return (7);
	else if (receiver->x > sender->x && receiver->y == sender->y)
		return (3);
	return (0);
}