/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Monitor
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>
#include <cstddef>
#include <memory>
#include <exception>
#include <iostream>
#include "Audio.hpp"

class Map;

class Network;

class Monitor {
public:
	Monitor();
	~Monitor();
	void	run();
	void	initWindow(const std::string ip, const std::string port);
	void	draw(const sf::Drawable &drawable);
	const sf::Vector2f	getSize() const;
	sf::Texture	&getTexture() const;
	Map	&getMap() const;
	Audio 	&getAudio() const;
	sf::RenderWindow	&getWindow() const;
	Network	&getNetwork() const;
	void	resize();
	void	teamWin(const std::string team);
private:
	void	initLoading();
	void	initNetwork(const std::string ip, const std::string port);
	std::unique_ptr<sf::Texture>		_texture;
	std::unique_ptr<sf::RenderWindow>	_window;
	std::unique_ptr<Network>		_network;
	std::unique_ptr<Map>			_map;
	std::unique_ptr<Audio>			_audio;
	std::unique_ptr<sf::Event>		_event;
	std::unique_ptr<sf::View>		_view;
};
