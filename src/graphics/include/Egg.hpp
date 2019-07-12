/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_

#include "IObject.hpp"
#include "Monitor.hpp"

class Egg : public IObject{
public:
	Egg(Monitor &monitor);
	~Egg();
	void	setState(bool _eclose);
	Type	 getType() const;
	void	setOwner(int owner_id);
	int	getOwner() const;
	int	getId() const;
	void	setId(int id);
	sf::Sprite	draw() const;
	void 	destroy();

private:
	Monitor		&_monitor;
	std::unique_ptr<sf::Sprite>	_sEgg;
	std::unique_ptr<sf::Texture>	_tEgg;
	bool	_dead;
	bool	_eclose;
	int	_owner;
	int	_id;
	int	_state;
};

#endif