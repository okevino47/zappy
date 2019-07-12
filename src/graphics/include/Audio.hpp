/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Audio
*/

#pragma once

#include <SFML/Audio.hpp>

class Audio
{
public:
	enum Type
	{
		MAIN,
		LEVEL,
		INCANTATION,
	};
	Audio();
	~Audio();
	bool	load();
	void	play(Type);
	void	playMain();
	void	playLevel();
	void	playIncantation();
private:
	sf::Music	_main;
	sf::Music	_level;
	sf::Music	_incantation;
};
