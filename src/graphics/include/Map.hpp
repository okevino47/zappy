/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <map>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Player.hpp"
#include "Gem.hpp"
#include "Egg.hpp"
#include "Food.hpp"
#include "Monitor.hpp"

class Map {
public:
	Map(Monitor &monitor);
	~Map();
	void	setMapSize(std::size_t width, std::size_t height);
	void	update();
	void	resize();
	void	initRessources(std::pair<std::size_t, std::size_t> pos, std::vector<std::size_t> quantity);
	std::pair<std::size_t, std::size_t>	getPlayerPosById(int id);
	std::vector<IObject*>	getObjectsOn(std::pair<std::size_t, std::size_t> pos);
	void	putObjectOn(IObject *object, std::pair<std::size_t, std::size_t> pos);
	void	onEvent(const sf::Event &event);
	IObject	*collectObjectOnMap(int res, std::pair<std::size_t, std::size_t> pos);
	void	removeObject(IObject *object);
	void	moveObject(IObject *object, std::pair<std::size_t, std::size_t> pos);
	void	setIncantationResult(std::pair<std::size_t, std::size_t> pos, int result);
	Player	*getPlayerById(int id);
	Egg	*getEggById(int id);
	std::pair<std::size_t, std::size_t>	getEggPosById(int id);
	void	addTeamName(const std::string teamName);
	std::vector<std::string>	getTeamsName() const;
	bool	isTeamName(const std::string teamName) const;
	std::pair<std::size_t, std::size_t>	getMapSize() const;
	void	drawGame();
	void	reloadMap();
	std::size_t	sizeGemsByKind(std::pair<std::size_t, std::size_t> pos, GemKind type);
	std::size_t	sizeObjectsByType(std::pair<std::size_t, std::size_t> pos, Type type);
	std::vector<std::size_t>	getListPlayer();

private:
	void	initWater();
	void	initGround();
	void	drawBorder(int posY, sf::Sprite &sprite);
	IObject	*getGemOn(GemKind gem, std::pair<std::size_t, std::size_t> pos);
	IObject *getFoodOn(std::pair<std::size_t, std::size_t> pos);
	std::map<std::pair<std::size_t, std::size_t>, std::vector<IObject *>>	_map;
	Monitor		&_monitor;
	sf::Texture	&_texture;
	std::unique_ptr<sf::RenderTexture>	_water;
	std::unique_ptr<sf::RenderTexture>	_ground;
	std::unique_ptr<sf::RenderTexture>	_action;
	std::pair<std::size_t, std::size_t>	_size;
	std::vector<std::string>		_teamsName;
	float		_scale;
	std::size_t	_tileSize;
	int		_xMin;
	int		_yMin;
};

#endif