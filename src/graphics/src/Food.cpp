/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Food
*/

#include "Food.hpp"

Food::Food(Monitor &monitor)
	: _monitor(monitor),
	_sFood(std::make_unique<sf::Sprite>(monitor.getTexture()))
{
	_sFood->setTextureRect(sf::IntRect(76, 104, 12, 14));
}

Food::~Food()
{}

void	Food::destroy()
{}

Type	Food::getType() const
{
	return Type::FOOD;
}

sf::Sprite	Food::draw() const
{
	return *_sFood;
}