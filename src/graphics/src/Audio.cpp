/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Audio
*/

#include "Audio.hpp"

Audio::Audio()
{}

Audio::~Audio()
{}

bool	Audio::load()
{
	if (!_main.openFromFile("src/graphics/res/zelda.ogg"))
		return false;
	if (!_level.openFromFile("src/graphics/res/level.ogg"))
		return false;
	if (!_incantation.openFromFile("src/graphics/res/incantation.ogg"))
		return false;
	_level.setLoop(false);
	_incantation.setLoop(false);
	return true;
}

void	Audio::playMain()
{
	if (_main.getStatus() == sf::Music::Paused ||
	    _main.getStatus() == sf::Music::Stopped)
		_main.play();
}

void	Audio::playLevel()
{
	_main.pause();
	_incantation.pause();
	if (_level.getStatus() != sf::Music::Playing)
		_level.play();
}

void	Audio::playIncantation()
{
	_main.pause();
	_level.pause();
	if (_incantation.getStatus() != sf::Music::Playing)
		_incantation.play();

}

void	Audio::play(Type type)
{
	switch (type)
	{
	case MAIN :
		playMain();
		break;
	case LEVEL :
		playLevel();
		break;
       	case INCANTATION :
		playIncantation();
		break;
	}
}
