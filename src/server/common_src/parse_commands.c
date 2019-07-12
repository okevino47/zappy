/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parse commands
*/

#include "server.h"

/*!
* @brief updates read on according to the size of the circular buffer
* @param buf pointer to circular buffer
* @param len value to add to read_on
*/
void update_read_on(cbuff_t *buf, int len)
{
	if (buf->read_on + len <= 4095)
		buf->read_on += len;
	else
		buf->read_on = (buf->read_on + len) - 4095;
}

/*!
* @brief copies read result in circular buffer
* @param buff_tmp temporary buffer containing read result
* @param c_buf circular buffer
*/
void copy_buffer(char *buff_tmp, cbuff_t *c_buf)
{
	for (int i = 0; buff_tmp[i] != '\0'; i++) {
		if (c_buf->write_on == 4095)
			c_buf->write_on = 0;
		c_buf->buffer[c_buf->write_on] = buff_tmp[i];
		c_buf->write_on++;
	}
	c_buf->buffer[c_buf->write_on] = '\0';
}

/*!
* @brief picks up the next command in circular buffer
* @param c_buf pointer to circular buffer of current client
* @return char *the command picked up
*/
char *pickup_command(cbuff_t *c_buf)
{
	char *request = &(c_buf->buffer[c_buf->read_on]);
	char *endline = strstr(request, "\n");
	int len;
	char *command;
	int i = 0;

	if (endline == NULL)
		return (NULL);
	len = (int) (endline - request) + 1;
	if (len <= 2)
		return (NULL);
	command = malloc(sizeof(char) * (len + 1));
	if (command == NULL)
		exit(ERROR);
	for (; request[i] != '\r' && request[i] != '\n'; i++)
		command[i] = request[i];
	command[i] = '\0';
	update_read_on(c_buf, len);
	return (command);
}

/*!
* @brief read the input from client and add an action to players actions
* @param fd file descriptor of current client
* @param server struct containing server infos
*/
void parse_commands(int fd, server_t *server)
{
	char *buff_tmp = malloc(sizeof(char) * 4096);
	char *command = NULL;
	players_t *player = get_current_player(fd, server);
	cbuff_t *c_buf;
	int read_ret;

	if (buff_tmp == NULL)
		exit(ERROR);
	if (fd == server->graph->fd)
		parse_graph_commands(server);
	else if (player != NULL) {
		c_buf = player->cbuff;
		memset(buff_tmp, 0, 4096);
		read_ret = read(fd, buff_tmp, 4095);
		handle_read_ret(read_ret, server, player);
		copy_buffer(buff_tmp, c_buf);
		while ((command = pickup_command(c_buf)))
			stock_command(command, fd, server);
	}
}