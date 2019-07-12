/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast_calc_sound
*/

#include "server.h"

/*!
* @brief convert broadcast direction according to player orientation
* @param orientation orientation of player
* @param broad_nb broad nb to convert
* @return int converted direction
*/
int convert_broad(int orientation, int broad_nb)
{
	switch (orientation) {
		case 1:
			return (broad_nb);
		case 2:
			return (convert_right(broad_nb));
		case 3:
			return (convert_down(broad_nb));
		case 4:
			return (convert_left(broad_nb));
	}
	return (0);
}

/*!
* @brief same as get_direction_broad but for last angles values
* @param angle angle of coming sound to convert to direction
* @return int direction of cmoing sound
*/
int get_other_direction_broad(int angle)
{
	if (angle >= 225 && angle < 270)
		return (4);
	else if (angle >= 270 && angle < 315)
		return (3);
	else {
		if (angle >= 315 && angle < 360)
			return (2);
	}
	return (0);
}

/*!
* @brief gets direction according to angle of sound
* @param angle angle of coming sound to convert to direction
* @return int direction of coming sound
*/
int get_direction_broad(int angle)
{
	if ((angle >= 0 && angle < 45) || angle == 360)
		return (1);
	else if (angle >= 45 && angle < 135) {
		if (angle >= 45 && angle < 90)
			return (8);
		else if (angle >= 90 && angle < 135)
			return (7);
	}
	else {
		if (angle >= 135 && angle < 180)
			return (6);
		else if (angle >= 180 && angle < 225)
			return (5);
		else
			return (get_other_direction_broad(angle));
	}
	return (0);
}

/*!
* @brief computes the angle where the sound comes from
* @param receiver player receiver of sound
* @param sender player sender of sound
* @return int direction of coming sound
*/
int calc_other_angles(players_t *receiver, players_t *sender)
{
	double coeff = (receiver->x - sender->x) / (receiver->y - sender->y);
	double radian = atan(coeff);
	int angle = (int)(radian * (180.0 / M_PI));
	int final_angle = 180 - (90 + angle);

	if (sender->x > receiver->x)
		final_angle += 90;
	else if (sender->x < receiver->x)
		final_angle += 270;
	return (get_direction_broad(final_angle));
}
/*!
* @brief gets the number of case around current player where sounds comes from
* according to receiver player orientation
* @param receiver player receiver of sound
* @param sender players sender of sound
* @return int number of case
*/
int get_broadcast_nb(players_t *receiver, players_t *sender)
{
	int broad_nb;

	if (receiver->x == sender->x && receiver->y == sender->y)
		return (0);
	broad_nb = x_equals_broad(receiver, sender);
	if (broad_nb == 0)
		broad_nb = y_equals_broad(receiver, sender);
	if (broad_nb == 0)
		broad_nb = calc_other_angles(receiver, sender);
	return (convert_broad(receiver->direction, broad_nb));
}