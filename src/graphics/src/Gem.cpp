/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Gem
*/

#include "Gem.hpp"

Gem::Gem(Monitor &monitor, GemKind gem)
	: _monitor(monitor), _gemKind(gem),
	_sGem(std::make_unique<sf::Sprite>(monitor.getTexture()))
{
	_sGem->setTextureRect(sf::IntRect(64, 104, 12, 20));
	initColor();
}

Gem::~Gem()
{}

void	Gem::destroy()
{}

void	Gem::initColor()
{
	if (_gemKind == GemKind::DERAUMERE)
		_sGem->setColor(sf::Color(0, 255, 214));
	else if (_gemKind == GemKind::LINEMATE)
		_sGem->setColor(sf::Color(0, 255, 56));
	else if (_gemKind == GemKind::MENDIANE)
		_sGem->setColor(sf::Color(255, 219, 0));
	else if (_gemKind == GemKind::PHIRAS)
		_sGem->setColor(sf::Color(244, 84, 179));
	else if (_gemKind == GemKind::SIBUR)
		_sGem->setColor(sf::Color(255, 129, 25));
}

Type	Gem::getType() const
{
	return Type::GEM;
}

GemKind	Gem::getGemKind() const
{
	return _gemKind;
}

sf::Sprite	Gem::draw() const
{
	return *_sGem;
}