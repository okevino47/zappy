/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Monitor.hpp"
#include "Map.hpp"

class Parser {
public:
	Parser(Monitor &monitor);
	~Parser();
	int	parse(std::string line);
private:
	int	findCommand();
	Monitor	&getMonitor() const;
	std::vector<std::string>	getLastCommand() const;
	static int	mapSize(const Parser &parser);
	static int	tileContent(const Parser &parser);
	static int	nameTeams(const Parser &parser);
	static int	connectPlayer(const Parser &parser);
	static int	playerPosition(const Parser &parser);
	static int	playerLevel(const Parser &parser);
	static int	playerInventory(const Parser &parser);
	static int	expulsion(const Parser &parser);
	static int	broadcast(const Parser &parser);
	static int	startIncantation(const Parser &parser);
	static int	endIncantation(const Parser &parser);
	static int	eggLaying(const Parser &parser);
	static int	dropRessource(const Parser &parser);
	static int	getRessource(const Parser &parser);
	static int	playerDeath(const Parser &parser);
	static int	placeEgg(const Parser &parser);
	static int	eggHatching(const Parser &parser);
	static int	playerFromEgg(const Parser &parser);
	static int	eggDeath(const Parser &parser);
	static int	endGame(const Parser &parser);
	static int	msgFromServer(const Parser &parser);
	static int	quitGame(const Parser &parser);
	static bool	isNum(const std::string arg);
	static bool	isFreePlayer(Map &map, const std::string str);
	static bool	isTeam(const Map &map, const std::string str);
	static bool	isExistingPlayer(Map &map, const std::string str);
	static bool	isExistEgg(Map &map, const std::string str);
	std::map<std::string, int (*)(const Parser &)>	_cmds;
	std::vector<std::string>	_args;
	Monitor		&_monitor;
};

#endif
