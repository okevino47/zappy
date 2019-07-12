/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** graphical client
*/

#include "server.h"

/*!
* @brief inits graph monitor in server struct
* @param fd file descriptor of graphical monitor
* @param server struct containig server infos
* @return int SUCCESS if okay, ERROR if dprintf failed
*/
int init_graph_monitor(int fd, server_t *server)
{
	delete_tmp_client(fd, server);
	server->graph->fd = fd;
	if (dprintf(fd, "CONNECTED\n") < 0)
		return (ERROR);
	return (SUCCESS);
}

/*!
* @brief inits graph struct
* @return graph_t * pointer to initialized struct
*/
graph_t *init_graph_struct(void)
{
	graph_t *graph = malloc(sizeof(graph_t));

	if (graph == NULL)
		exit(ERROR);
	graph->fd = -1;
	graph->cbuff = init_cbuff_struct();
	return (graph);
}