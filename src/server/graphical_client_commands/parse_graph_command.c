/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parse graph commands
*/

#include "server.h"

/*!
* @brief executes graphical commands
* @param command command to execute
* @param server struct containing server infos
* @return always "SUCCESS"
*	  [ TUs purpose ]
*/
int exec_commands_graph(char *command, server_t *server)
{
	fp_g *fp = fp_init_graph();
	char **com_array = command_array_graph();
	char **args = str_to_word_array(command);
	int tmp = 0;

	for (int i = 0; fp[i] != NULL; i++) {
		if (strcmp(com_array[i], command) == 0) {
			fp[i](server, args);
			tmp = 1;
		}
	}
	if (tmp == 0)
		suc(server);
	return (SUCCESS);
}

/*!
* @brief handles read return of graphical client
* @param read_ret read return
* @param server struct containing server infos
* @param fd file descriptor of graphical monitor
*/
void handle_read_ret_graph(int read_ret, server_t *server, int fd)
{
	if (read_ret < 0)
		exit (ERROR);
	if (read_ret == 0)
		remove_client(fd, server->active_set);
}

/*!
* @brief parses graphical commands received by server from graphical monitor
* @param server struct containing server infos
*/
void parse_graph_commands(server_t *server)
{
	char *buff_tmp = malloc(sizeof(char) * 1024);
	char *command = NULL;
	graph_t *graph = server->graph;
	int read_ret;

	if (buff_tmp == NULL)
		exit(ERROR);
	memset(buff_tmp, 0, 1023);
	read_ret = read(graph->fd, buff_tmp, 1023);
	handle_read_ret_graph(read_ret, server, graph->fd);
	copy_buffer(buff_tmp, graph->cbuff);
	while ((command = pickup_command(graph->cbuff)))
		exec_commands_graph(command, server);
}