/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Connect
*/

#include "Network.hpp"

Network::Network(Monitor &monitor)
	:_ip(std::string("")), _port(0), _fd(-1),
	_input(nullptr),
	_parser(std::make_unique<Parser>(monitor))
{}

Network::~Network()
{
	if (_input)
		fclose(_input);
	_parser.reset();
}

void	Network::init()
{
	struct sockaddr_in	s_in;

	if (_port == 0 || _ip == "")
		throw std::logic_error("no data");
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(_port);
	s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
	_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_fd == -1)
		throw std::logic_error("socket");
	if (connect(_fd, (struct sockaddr *)&s_in, sizeof(s_in)) != 0)
		throw std::logic_error("connect");
	_input = fdopen(_fd, "r");
}

void	Network::setIp(const std::string ip)
{
	_ip = std::string(ip);
}

void	Network::setPort(int port)
{
	if (port < 0 || port > USHRT_MAX)
		throw std::logic_error("port isn't a short");
	_port = port;
}

void	Network::run()
{
	fd_set	read;
	timeval timeout = {0, 1};
	std::string	line;

	FD_ZERO(&read);
	FD_SET(_fd, &read);
	if (select(_fd + 1, &read, nullptr, nullptr, &timeout) == -1)
		throw std::logic_error("select");
	if (FD_ISSET(_fd, &read)) {
		line = readLine();
		if (line == "")
			return ;
		_parser->parse(line);
	}
	return ;
}

void	Network::requestMapSize()
{
	try {
		writeStr(std::string("msz"));
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestContentOn(std::size_t x, std::size_t y)
{
	std::stringstream	msg;

	msg.str("bct ");
	msg << x << " " << y;
	try {
		writeStr(msg.str());
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestAllContent()
{
	try {
		writeStr(std::string("mct"));
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestNameTeams()
{
	try {
		writeStr(std::string("tna"));
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestPlayerPosition(std::size_t player_id)
{
	std::stringstream	msg;

	msg.str("ppo #");
	msg << player_id;
	try {
		writeStr(msg.str());
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestPlayerLevel(std::size_t player_id)
{
	std::stringstream	msg;

	msg.str("plv #");
	msg << player_id;
	try {
		writeStr(msg.str());
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestPlayerInventory(std::size_t player_id)
{
	std::stringstream	msg;

	msg.str("pin #");
	msg << player_id;
	try {
		writeStr(msg.str());
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::writeStr(const std::string string)
{
	int	written = dprintf(_fd, "%s\n", string.c_str());
	int	len = string.size();

	if (written < 0)
		throw std::logic_error("write");
	try {
		if (written < len)
			writeStr(std::string(&string.c_str()[written]));
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

void	Network::requestQuit()
{
	try {
		writeStr("quit");
	} catch (const std::logic_error &e) {
		throw std::logic_error(e.what());
	}
}

char	Network::readChar()
{
	return fgetc(_input);
}

std::string	Network::readLine()
{
	std::string	str("");
	char		c = readChar();

	while (c != '\n' && c != EOF) {
		str.push_back(c);
		c = readChar();
	}
	return str;
}

void	Network::waitResponse()
{
	std::string	line;

	line = readLine();
	if (line == "")
		return ;
	if (!_parser->parse(line))
		throw std::logic_error("error");
}

void	Network::connectServer()
{
	if (_fd == -1)
		return ;
	if (readLine() != "WELCOME")
		throw std::logic_error("no welcome");
	try {
		writeStr(std::string("MONITOR"));
	} catch (const std::logic_error &e) {
		throw std::logic_error("write");
	}
	if (readLine() != "CONNECTED")
		throw std::logic_error("no connected");
}
