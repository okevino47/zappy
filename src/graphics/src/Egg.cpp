/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Egg
*/

#include "Egg.hpp"

Egg::Egg(Monitor &monitor)
	: _monitor(monitor), _dead(false)
{
	sf::Sprite	sprite(_monitor.getTexture());
	sf::RenderTexture	rd;

	sprite.setTextureRect(sf::IntRect(88, 104, 100, 25));
	rd.create(100, 25);
	rd.draw(sprite);
	rd.display();
	_tEgg = std::make_unique<sf::Texture>(rd.getTexture());
	setState(false);
}

Egg::~Egg()
{}

Type	Egg::getType() const
{
	return Type::EGG;
}

void	Egg::setState(bool state)
{
	if (!state) {
		_sEgg = std::make_unique<sf::Sprite>(*_tEgg);
		_sEgg->setTextureRect(sf::IntRect(0, 0, 25, 25));
	} else {
		_sEgg = std::make_unique<sf::Sprite>(*_tEgg);
		_sEgg->setTextureRect(sf::IntRect(75, 0, 25, 25));
	}
	_state = state;
}

void	Egg::setOwner(int owner_id)
{
	_owner = owner_id;
}

int	Egg::getOwner() const
{
	return _owner;
}

void	Egg::setId(int id)
{
	_id = id;
}

int	Egg::getId() const
{
	return _id;
}

sf::Sprite	Egg::draw() const
{
	if (_dead)
		return sf::Sprite();
	return *_sEgg;
}

void 	Egg::destroy()
{
	_dead = true;
}