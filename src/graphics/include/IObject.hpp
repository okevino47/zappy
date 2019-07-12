/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** IObject
*/

#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum Type {
	FOOD,
	PLAYER,
	GEM,
	EGG
};

class IObject {
public:
	virtual	~IObject() = default;
	virtual	Type	getType() const = 0;
	virtual sf::Sprite	draw() const = 0;
	virtual void	destroy() = 0;
};

#endif
