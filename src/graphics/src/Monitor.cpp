/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Monitor
*/

#include "Monitor.hpp"
#include "Map.hpp"
#include "Network.hpp"

Monitor::Monitor()
	: _texture(std::make_unique<sf::Texture>()),
	_window(std::make_unique<sf::RenderWindow>()),
	_network(std::make_unique<Network>(*this)),
	_audio(std::make_unique<Audio>()),
	_event(std::make_unique<sf::Event>()),
	_view(std::make_unique<sf::View>(_window->getDefaultView()))
{
	std::srand(std::time(nullptr));
	_audio->load();
}

Monitor::~Monitor()
{}

void	Monitor::run()
{
	int	i = 0;

	while (_window->isOpen()) {
		while (_window->pollEvent(*_event)) {
			if (_event->type == sf::Event::Resized)
				resize();
			if (_event->type == sf::Event::Closed) {
				_network->requestQuit();
				_network->waitResponse();
			}
			_map->onEvent(*_event);
		}
		_window->clear();
		if (i == 999) 
			_network->requestAllContent();
		i = (i + 1) % 1000;
		_network->run();
		_map->update();
		_window->display();
	}
}

void	Monitor::teamWin(const std::string team)
{
	std::cout << team << " wins!" << std::endl;
	_network->requestQuit();
	_network->waitResponse();
}

void	Monitor::draw(const sf::Drawable &drawable)
{
	_window->draw(drawable);
}

void	Monitor::resize()
{
	sf::Vector2f 		winSize = static_cast<sf::Vector2f>(
		_window->getSize());

	_window->setSize(_window->getSize());
	_view->setCenter(winSize / 2.0f);
	_view->setSize(winSize);
	_view = std::make_unique<sf::View>(
		sf::FloatRect(0.0f, 0.0f, winSize.x, winSize.y));
	_window->setView(*_view);
	_map->resize();
}

void	Monitor::initWindow(const std::string ip, const std::string port)
{	
	_window->create(
		sf::VideoMode(800, 600),
		"Zappy Monitor",
		sf::Style::Close | sf::Style::Resize);
	if (!_texture->loadFromFile("src/graphics/res/texture.png"))
		throw std::logic_error("Can't load textures");
	_map = std::make_unique<Map>(*this);
	initLoading();
	initNetwork(ip, port);
	resize();
	_audio->play(Audio::Type::MAIN);
}

void	Monitor::initNetwork(const std::string ip, const std::string port)
{
	_network->setIp(ip);
	_network->setPort(stoi(port));
	_network->init();
	_network->connectServer();
	_network->requestMapSize();
	_network->waitResponse();
	_network->requestNameTeams();
	_network->waitResponse();
	_network->requestAllContent();
	for (std::size_t i = 0; i != _map->getMapSize().first * _map
		->getMapSize().second; i++)
	_network->waitResponse();
}

void	Monitor::initLoading()
{
	sf::Texture	t_load;
	sf::Sprite	s_load;

	t_load.loadFromFile("src/graphics/res/load.png");
	s_load.setTexture(t_load);
	s_load.setScale(sf::Vector2f(0.5, 0.5));
	draw(s_load);
	_window->display();
}

const sf::Vector2f	Monitor::getSize() const
{
	return _window->getView().getSize();
}

sf::Texture	&Monitor::getTexture() const
{
	return *_texture;
}

Map	&Monitor::getMap() const
{
	return *_map;
}

Audio	&Monitor::getAudio() const
{
	return* _audio;
}

sf::RenderWindow	&Monitor::getWindow() const
{
	return *_window;
}

Network	&Monitor::getNetwork() const
{
	return *_network;
}
