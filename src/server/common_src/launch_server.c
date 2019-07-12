/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** launch server
*/

#include "server.h"

/*!
* @brief accepts client if its new or treats its requests if necessary
* @param i the fd of client
* @param server struct containing server infos
* @param active_set set of file descriptors
*/
void client_action(int i, server_t *server, fd_set *active_set)
{
	int new_fd;
	struct sockaddr_in addr;
	socklen_t size = sizeof(addr);
	int ret_tmp;

	if (i == server->fd) {
		new_fd = accept(server->fd, (struct sockaddr *) &addr, &size);
		if (new_fd < 0)
			exit(ERROR);
		add_tmp_client(new_fd, server);
		FD_SET(new_fd, active_set);
	}
	else {
		ret_tmp = check_client(i, server);
		if (ret_tmp == ERROR)
			remove_client(i, active_set);
		else if (ret_tmp == FAILURE)
			parse_commands(i, server);
	}
}

/*!
* @brief loops on fd of fd set
* @param read_set set of file descriptors
* @param active_set set of file descriptors
* @param server struct containing server infos
*/
void handle_client(fd_set read_set, fd_set *active_set, server_t *server)
{
	for (int i = 0; i < FD_SETSIZE; i++) {
		if (FD_ISSET(i, &read_set))
			client_action(i, server, active_set);
	}
}

/*!
* @brief actualises the timeout for select
* @param tv struct to give to select
* @param t_old time before actualisation
* @param t_act time after actualisation
* @param t time of a cycle in seconds
* @return struct timeval * the struct to give to select for timeout
*/
struct timeval *get_timeout(struct timeval *tv, struct timeb t_old, \
				struct timeb t_act, server_t *server)
{
	float t = (1.0 / (float)(server->freq));
	float t1;
	float t2;

	t1 = (float)(t_old.time) + (((float)(t_old.millitm)) / 1000.0);
	t2 = (float)(t_act.time) + (((float)(t_act.millitm)) / 1000.0);
	if (t2 - t1 >= t) {
		tv->tv_sec = (int)t;
		tv->tv_usec = (t - (int)t) * 1000000;
	}
	else {
		t1 = t - (t2 - t1);
		tv->tv_sec = (int)t1;
		tv->tv_usec = (t1 - (int)t1) * 1000000;
	}
	return (tv);
}

/*!
* @brief inits a timeval struct for select timeout
* @param tv struct timeval
* @param t time of a cycle in seconds
* @return struct timeval struct for select timeout
*/
struct timeval init_timeval(struct timeval tv, server_t *server)
{
	float t = (1.0 / (float)(server->freq));

	tv.tv_sec = (int)t;
	tv.tv_usec = (t - (int)t) * 1000000;
	return (tv);
}

/*!
* @brief launch the server and uses select to handle clients
* @param server struct containing server infos
*/
void launch_server(server_t *server)
{
	fd_set active_set;
	fd_set read_set;
	struct timeb t_old;
	struct timeb t_act;
	struct timeval tv = init_timeval(tv, server);

	ftime(&t_act);
	FD_ZERO(&active_set);
	FD_SET(server->fd, &active_set);
	while (1) {
		server->map = random_ressources_generation(server);
		t_old = t_act;
		ftime(&t_act);
		server->active_set = &active_set;
		get_timeout(&tv, t_old, t_act, server);
		read_set = active_set;
		if (select(FD_SETSIZE, &read_set, NULL, NULL, &tv) < 0)
			exit(ERROR);
		update_game(read_set, server, &active_set);
	}
}