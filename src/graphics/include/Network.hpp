/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Connect
*/

#pragma once

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <climits>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <string>
#include <stdexcept>
#include <climits>
#include <ext/stdio_filebuf.h>
#include <memory>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Parser.hpp"
#include "Monitor.hpp"

class Network {
public:
	Network(Monitor &monitor);
	~Network();
	void	init();
	void	connectServer();
	void	setIp(const std::string ip);
	void	setPort(int port);
	void	run();
	void	waitResponse();
	void	requestContentOn(std::size_t x, std::size_t y);
	void	requestMapSize();
	void	requestAllContent();
	void	requestNameTeams();
	void	requestPlayerPosition(std::size_t player_id);
	void	requestPlayerLevel(std::size_t player_id);
	void	requestPlayerInventory(std::size_t player_id);
	void	requestQuit();;
private:
	void	writeStr(const std::string str);
	char	readChar();
	std::string	readLine();
	void	createInput();
	void	createOutput();
	std::string	_ip;
	unsigned short	_port;
	int		_fd;
	FILE		*_input;
	std::unique_ptr<Parser>	_parser;
};
