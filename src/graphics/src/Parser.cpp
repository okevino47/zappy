/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Network.hpp"

Parser::Parser(Monitor &monitor)
	: _monitor(monitor)
{
	_cmds.insert(std::make_pair("msz", &mapSize));
	_cmds.insert(std::make_pair("bct", &tileContent));
	_cmds.insert(std::make_pair("tna", &nameTeams));
	_cmds.insert(std::make_pair("pnw", &connectPlayer));
	_cmds.insert(std::make_pair("ppo", &playerPosition));
	_cmds.insert(std::make_pair("plv", &playerLevel));
	_cmds.insert(std::make_pair("pin", &playerInventory));
	_cmds.insert(std::make_pair("pex", &expulsion));
	_cmds.insert(std::make_pair("pbc", &broadcast));
	_cmds.insert(std::make_pair("pic", &startIncantation));
	_cmds.insert(std::make_pair("pie", &endIncantation));
	_cmds.insert(std::make_pair("pfk", &eggLaying));
	_cmds.insert(std::make_pair("pdr", &dropRessource));
	_cmds.insert(std::make_pair("pgt", &getRessource));
	_cmds.insert(std::make_pair("pdi", &playerDeath));
	_cmds.insert(std::make_pair("enw", &placeEgg));
	_cmds.insert(std::make_pair("eht", &eggHatching));
	_cmds.insert(std::make_pair("ebo", &playerFromEgg));
	_cmds.insert(std::make_pair("edi", &eggDeath));
	_cmds.insert(std::make_pair("seg", &endGame));
	_cmds.insert(std::make_pair("smg", &msgFromServer));
	_cmds.insert(std::make_pair("bye", &quitGame));
}

Parser::~Parser()
{}

int	Parser::parse(std::string line)
{
	std::string	temp;
	std::size_t	pos;

	_args.clear();
	while (!line.empty()) {
		pos = line.find(" ");
		if (pos == line.npos) {
			temp = line.substr(0, line.size());
			if (temp != "")
				_args.push_back(temp.c_str());
			line.clear();
			continue ;
		}
		temp = line.substr(0, pos);
		if (temp != "")
			_args.push_back(temp.c_str());
		line.erase(0, pos + 1);
	}
	return findCommand();
}

int	Parser::findCommand()
{
	int	result;

	for (auto it = _cmds.begin(); it != _cmds.end(); it++) {
		if (_args[0] == it->first) {
			result = it->second(*this);
			return result;
		}
	}
	return 1;
}

Monitor	&Parser::getMonitor() const
{
	return _monitor;
}

std::vector<std::string>	Parser::getLastCommand() const
{
	return _args;
}

bool	Parser::isNum(const std::string str)
{
	for (auto i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool	Parser::isExistingPlayer(Map &map, const std::string str)
{
	if (!isNum(str))
		return false;
	if (!map.getPlayerById(stoi(str)))
		return false;
	return true;
}

bool	Parser::isFreePlayer(Map &map, const std::string str)
{
	if (str[0] != '#')
		return false;
	if (!isNum(str.substr(1, str.size() - 1)))
		return false;
	if (map.getPlayerById(stoi(str.substr(1, str.size() - 1))))
		return false;
	return true;
}

bool	Parser::isTeam(const Map &map, const std::string str)
{
	return map.isTeamName(str);
}

bool	Parser::isExistEgg(Map &map, const std::string str)
{
	if (!isNum(str))
		return false;
	if (!map.getEggById(stoi(str)))
		return false;
	return true;
}

int	Parser::mapSize(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 3)
		return 0;
	if (!isNum(args[1]) || !isNum(args[2]))
		return 0;
	parser.getMonitor().getMap().setMapSize(stoi(args[1]), stoi(args[2]));
	return 1;
}

int	Parser::tileContent(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 10)
		return 0;
	if (!isNum(args[1]) || !isNum(args[2]) || !isNum(args[3]) ||
		!isNum(args[4]) || !isNum(args[5]) || !isNum(args[6]) ||
		!isNum(args[7]) || !isNum(args[8]) || !isNum(args[9]))
		return 0;
	parser.getMonitor().getMap().initRessources(
		std::make_pair(stoul(args[1]), stoul(args[2])),
		std::vector<std::size_t>{stoul(args[3]), stoul(args[4]),
		stoul(args[5]), stoul(args[6]), stoul(args[7]), stoul(args[8]),
		stoul(args[9])}
	);
	return 1;
}

int	Parser::nameTeams(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	parser.getMonitor().getMap().addTeamName(args[1]);
	return 1;
}

int	Parser::connectPlayer(const Parser &parser)
{
	auto args = parser.getLastCommand();
	Player	*player;

	if (args.size() != 7)
		return 0;
	if (!isFreePlayer(parser.getMonitor().getMap(), args[1]) ||
		!isTeam(parser.getMonitor().getMap(), args[6]) ||
		!isNum(args[2]) || !isNum(args[3]) || !isNum(args[4]) ||
		!isNum(args[5]))
		return 0;
	player = new Player(parser.getMonitor());
	player->setId(stoi(args[1].substr(1, args[1].size() - 1)));
	player->setRotation(stoi(args[4]));
	player->setLevel(stoi(args[5]));
	player->setTeam(args[6]);
	parser.getMonitor().getMap().putObjectOn(player,
		std::make_pair(stoi(args[2]), stoi(args[3])));
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::playerPosition(const Parser &parser)
{
	auto args = parser.getLastCommand();
	Player	*player;

	if (args.size() != 5)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]) ||
		!isNum(args[2]) || !isNum(args[3]) || !isNum(args[4]))
		return 0;
	player = parser.getMonitor().getMap().getPlayerById(stoi(args[1]));
	if (!player)
		return 0;
	player->setRotation(stoi(args[4]));
	parser.getMonitor().getMap().moveObject(player, std::make_pair(
		stoi(args[2]), stoi(args[3])));
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::playerLevel(const Parser &parser)
{
	auto args = parser.getLastCommand();
	Player	*player;

	if (args.size() != 3)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]) ||
		isNum(args[2]))
		return 0;
	player = parser.getMonitor().getMap().getPlayerById(stoi(args[1]));
	if (!player)
		return 0;
	player->setLevel(stoi(args[2]));
	return 1;
}

int	Parser::playerInventory(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 11)
		return 0;
	if (isExistingPlayer(parser.getMonitor().getMap(), args[1]) ||
		!isNum(args[4]) || !isNum(args[5]) || !isNum(args[6]) ||
		!isNum(args[7]) || !isNum(args[8]) || !isNum(args[9]) ||
		!isNum(args[10]))
		return 0;
	parser.getMonitor().getMap().getPlayerById(stoi(args[1]))
		->chargeNewInventory(
			std::vector<std::size_t>{
			stoul(args[4]), stoul(args[5]), stoul(args[6]),
			stoul(args[7]), stoul(args[8]), stoul(args[9]),
			stoul(args[10])}
		);
	return 1;
}

int	Parser::expulsion(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getNetwork().requestPlayerPosition(stoul(args[1]));
	return 1;
}

int	Parser::broadcast(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 3)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getMap().getPlayerById(stoi(args[1]))->speak(true);
	return 1;
}

int	Parser::startIncantation(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() < 5)
		return 0;
	if (!isNum(args[1]) || !isNum(args[2]) || !isNum(args[3]))
		return 0;
	for (std::size_t i = 4; i < args.size(); i++) {
		if (!isExistingPlayer(parser.getMonitor().getMap(), args[i]))
			continue ;
		parser.getMonitor().getMap().getPlayerById(stoi(args[i]))
			->incante(true);
	}
	parser.getMonitor().getAudio().play(Audio::Type::INCANTATION);
	parser.getMonitor().getAudio().play(Audio::Type::MAIN);
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::endIncantation(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 4)
		return 0;
	if (!isNum(args[1]) || !isNum(args[2]))
		return 0;
	parser.getMonitor().getMap().setIncantationResult(
		std::make_pair(stoi(args[1]), stoi(args[2])), 
		((args[3] == "ok") ? 1 : 0));
	parser.getMonitor().getAudio().play(Audio::Type::LEVEL);
	parser.getMonitor().getAudio().play(Audio::Type::MAIN);
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::eggLaying(const Parser &parser)
{
	std::cout << parser.getLastCommand()[0] << std::endl;
	return 1;
}

int	Parser::dropRessource(const Parser &parser)
{
	auto	args = parser.getLastCommand();
	int	ressource;
	IObject *tmp;

	if (args.size() != 3)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]) ||
		!isNum(args[2]))
		return 0;
	ressource = stoi(args[2]);
	if (ressource > 6)
		return 0;
	tmp = parser.getMonitor().getMap().getPlayerById(stoi(args[1]))
		->removeItemFromInventory(ressource);
	if (!tmp)
		return 1;
	parser.getMonitor().getMap().putObjectOn(tmp, parser.getMonitor()
		.getMap().getPlayerPosById(stoi(args[1])));
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::getRessource(const Parser &parser)
{
	auto	args = parser.getLastCommand();
	int	ressource;
	IObject	*tmp;

	if (args.size() != 3)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]) ||
		!isNum(args[2]))
		return 0;
	ressource = stoi(args[2]);
	tmp = parser.getMonitor().getMap().collectObjectOnMap(ressource,
		parser.getMonitor().getMap().getPlayerPosById(stoi(args[1])));
	if (tmp == nullptr)
		return 0;
	parser.getMonitor().getMap().getPlayerById(stoi(args[1]))
		->addItemInInventory(tmp);
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::playerDeath(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isExistingPlayer(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getMap().getPlayerById(stoi(args[1]))
		->destroy();
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::placeEgg(const Parser &parser)
{
	auto args = parser.getLastCommand();
	Egg	*tmp;

	if (args.size() != 5)
		return 0;
	if (isExistEgg(parser.getMonitor().getMap(), args[1])
		|| !isExistingPlayer(parser.getMonitor().getMap(), args[2]) ||
		!isNum(args[3]) || !isNum(args[4]))
		return 0;
	tmp = new Egg(parser.getMonitor());
	tmp->setId(stoi(args[1]));
	tmp->setOwner(stoi(args[2]));
	parser.getMonitor().getMap().putObjectOn(
		tmp, std::make_pair(stoi(args[3]), stoi(args[4])));
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::eggHatching(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isExistEgg(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getMap().getEggById(stoi(args[1]))
		->setState(true);
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::playerFromEgg(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isExistEgg(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getMap().getEggById(stoi(args[1]))
		->destroy();
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::eggDeath(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isExistEgg(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().getMap().getEggById(stoi(args[1]))
		->destroy();
	parser.getMonitor().getMap().drawGame();
	return 1;
}

int	Parser::endGame(const Parser &parser)
{
	auto args = parser.getLastCommand();

	if (args.size() != 2)
		return 0;
	if (!isTeam(parser.getMonitor().getMap(), args[1]))
		return 0;
	parser.getMonitor().teamWin(args[1]);
	return 1;
}

int	Parser::msgFromServer(const Parser &parser)
{
	if (parser.getLastCommand().size() != 2)
		return 0;
	std::cout << parser.getLastCommand()[1] << std::endl;
	return 1;
}

int	Parser::quitGame(const Parser &parser)
{
	parser.getMonitor().getWindow().close();
	return 1;
}
