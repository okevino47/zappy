/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** update game
*/

#include "server.h"

/*!
* @brief updates all necessary game cycles and ressources
* @param active_set fd set for select
* @param read_set fd set for select
* @param server struct containing server infos
*/
void update_game(fd_set read_set, server_t *server, fd_set *active_set)
{
	handle_client(read_set, active_set, server);
	update_cycles(server, active_set);
	end_game(server, active_set);
}