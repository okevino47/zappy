/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <iostream>
#include "Monitor.hpp"

int	main(int ac, char **av)
{
	Monitor	window;

	if (ac != 3) {
		std::cerr << "Not good parameters" << std::endl <<
		"Please enter the ip address and the port" << std::endl;
		return 84;
	}
	try {
		window.initWindow(av[1], av[2]);
		window.run();
	} catch (const std::logic_error &e) {
		std::cerr << "Error: " <<  e.what() <<
		" function had a problem" << std::endl;
		return 84;
	}
	return 0;
}
