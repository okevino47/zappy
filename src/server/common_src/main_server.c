/*
** EPITECH PROJECT, 2018
** irc
** File description:
** main
*/

#include "server.h"

/*!
* @brief prints the -help of the program
*/
void print_help(void)
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1 na");
	printf("me2 ... -c clientsNb -f freq\n\tport\t  is the port number\n");
	printf("\twidth\t  is the width of the world\n\theight\t  is the hei");
	printf("ght of the world\n\tnameX\t  is the name of the team X\n\tcl");
	printf("ientsNb is the number of authorized clients per team\n\tfre");
	printf("q\t  is the reciprocal of time unit for execution of actions");
	printf("\n");
	exit (SUCCESS);
}

int main(int ac, char **av)
{
	server_t *server;

	if (ac == 2 && strcmp(av[1], "-help") == 0)
		print_help();
	srand(time(NULL));
	handle_params(av, ac);
	server = init_server_struct(create_socket(atoi(av[2])), \
	atoi(av[ac - 1]), atoi(av[4]), atoi(av[6]));
	init_teams_list(server, av);
	launch_server(server);
	return (SUCCESS);
}