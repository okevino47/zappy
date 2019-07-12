/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(Monitor &monitor)
	: _monitor(monitor), _charNum(std::rand() % 4), _incantation(false), 
	_speak(false), _level(1), _fromEgg(false), _dead(false)
{
	setRotation(3);
}

Player::~Player()
{}

void	Player::setRotation(int rotation)
{
	sf::RenderTexture	rd;
	sf::Sprite	sprite(_monitor.getTexture());
	
	_rotation = rotation - 1;
	if (!_incantation)
		sprite.setTextureRect(sf::IntRect(0, _charNum * 26,
			152, 26));
	else
		sprite.setTextureRect(sf::IntRect(0, _charNum * 26 +
			104, 152, 26));
	rd.create(152, 26);
	rd.draw(sprite);
	rd.display();
	_tPlayer = std::make_unique<sf::Texture>(rd.getTexture());
	_sPlayer = std::make_unique<sf::Sprite>(*_tPlayer);
	_sPlayer->setTextureRect(sf::IntRect(19 * _rotation, 0, 19, 26));	
}

Type	Player::getType() const
{
	return Type::PLAYER;
}

void	Player::setId(int id)
{
	_id = id;
}

int	Player::getId() const
{
	return _id;
}

sf::Sprite	Player::draw() const
{
	if (!_dead)
		return *_sPlayer;
	return sf::Sprite();
}

void	Player::destroy()
{
	_dead = true;
}

void	Player::isFromEgg(bool state)
{
	_fromEgg = state;
}

bool	Player::isFromEgg() const
{
	return _fromEgg;
}

void	Player::incante(bool state)
{
	_sPlayer->setTexture(*_tPlayer);
	if (state) {
		_sPlayer->setTextureRect(sf::IntRect(19 * _rotation + 76,
		0, 19, 26));
	} else {
		_sPlayer->setTextureRect(sf::IntRect(19 * _rotation,
		0, 19, 26));
	}
	_incantation = state;
}

bool	Player::isIncanting() const
{
	return _incantation;
}

void	Player::speak(bool state)
{
	_speak = state;
}

bool	Player::isSpeaking() const
{
	return _speak;
}

void	Player::setLevel(int level)
{
	_level = level;
}

int	Player::getLevel() const
{
	return _level;
}

void	Player::addItemInInventory(IObject *obj)
{
	_inventory.push_back(obj);
}

void	Player::chargeNewInventory(std::vector<std::size_t> quantity)
{
	_inventory.clear();
	for (std::size_t i = 0; i < quantity[0]; i++)
		_inventory.push_back(new Food(_monitor));
	for (std::size_t i = 0; i < quantity[1]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::LINEMATE));
	for (std::size_t i = 0; i < quantity[2]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::DERAUMERE));
	for (std::size_t i = 0; i < quantity[3]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::SIBUR));
	for (std::size_t i = 0; i < quantity[4]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::MENDIANE));
	for (std::size_t i = 0; i < quantity[5]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::PHIRAS));
	for (std::size_t i = 0; i < quantity[6]; i++)
		_inventory.push_back(new Gem(_monitor, GemKind::THYSTAME));
}

IObject	*Player::removeItemFromInventory(int ressource)
{
	if (_inventory.empty())
		return nullptr;
	for (auto it = _inventory.begin(); it != _inventory.end(); it++) {
		if (ressource == 0 && (*it)->getType() == Type::FOOD) {
			_inventory.erase(it);
			return *it;
		} else if (ressource > 0 && ressource < 7) {
			if ((*it)->getType() != Type::GEM)
				continue ;
			if (dynamic_cast<Gem *>(*it)->getGemKind() == 
				static_cast<GemKind>(ressource - 1)) {
				_inventory.erase(it);
				return *it;
			}
		}
	}
	return nullptr;
}

void	Player::setTeam(const std::string str)
{
	_team = std::string(str);
}

std::string	Player::getTeam() const
{
	return _team;
}