/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <cstdlib>
#include "IObject.hpp"
#include "Monitor.hpp"
#include "Gem.hpp"
#include "Food.hpp"

class Player : public IObject {
public:
	Player(Monitor &monitor);
	~Player();
	Type	getType() const;
	int	getId() const;
	sf::Sprite	draw() const;
	void	setRotation(int rotation);
	void	setId(int id);
	void	isFromEgg(bool state);
	bool	isFromEgg() const;
	void	incante(bool state);
	bool	isIncanting() const;
	void	speak(bool state);
	bool	isSpeaking() const;
	void	setLevel(int level);
	int	getLevel() const;
	void	chargeNewInventory(std::vector<std::size_t> quantity);
	void	addItemInInventory(IObject *obj);
	IObject *removeItemFromInventory(int ressource);
	void	setTeam(const std::string team);
	std::string	getTeam() const;
	void 	destroy();

private:
	Monitor		&_monitor;
	std::unique_ptr<sf::Sprite>	_sPlayer;
	std::unique_ptr<sf::Texture>	_tPlayer;
	std::vector<IObject *>	_inventory;
	std::string	_team;
	int		_rotation;
	int		_charNum;
	int		_id;
	bool		_incantation;
	bool		_speak;
	int		_level;
	bool		_fromEgg;
	bool		_dead;
};

#endif