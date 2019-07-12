/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** socket
*/

#include "server.h"

/*!
* @brief creates a new socket
* @param port the port to open the socket on
* @return int the file descriptor corresponding to the new socket
*/
int create_socket(int port)
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr_s;

	bzero(&addr_s, sizeof(addr_s));
	addr_s.sin_family = AF_INET;
	addr_s.sin_addr.s_addr = INADDR_ANY;
	addr_s.sin_port = htons(port);
	if (fd == -1 || bind(fd, (const struct sockaddr *) &addr_s, \
	sizeof(addr_s)) == -1 || listen(fd, 100) == -1)
		exit(84);
	return (fd);
}