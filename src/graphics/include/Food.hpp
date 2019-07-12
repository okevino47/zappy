/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Food
*/

#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "IObject.hpp"
#include "Monitor.hpp"

class Food : public IObject {
public:
	Food(Monitor &monitor);
	~Food();
	Type	getType() const;
	sf::Sprite	draw() const;
	void	destroy();

private:
	Monitor		&_monitor;
	std::unique_ptr<sf::Sprite>	_sFood;
};

#endif