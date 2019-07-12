/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Gem
*/

#ifndef GEM_HPP_
#define GEM_HPP_

#include "IObject.hpp"
#include "Monitor.hpp"

enum GemKind {
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

class Gem : public IObject {
public:
	Gem(Monitor &monitor, GemKind gem);
	~Gem();
	Type	getType() const;
	GemKind	getGemKind() const;
	sf::Sprite	draw() const;
	void destroy();

private:
	void	initColor();
	Monitor	&_monitor;
	GemKind	_gemKind;
	std::unique_ptr<sf::Sprite>	_sGem;
};

#endif