/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Map
*/

#include "Map.hpp"
#include "Network.hpp"

Map::Map(Monitor &monitor)
	: _monitor(monitor),
	_texture(monitor.getTexture()),
	_water(std::make_unique<sf::RenderTexture>()),
	_ground(std::make_unique<sf::RenderTexture>()),
	_action(std::make_unique<sf::RenderTexture>()), _scale(2),
	_tileSize(32)
{}

Map::~Map()
{}

void	Map::resize()
{
	_xMin = (_monitor.getSize().x / 2.0f) - (_tileSize * _scale * _size.first / 2.0f);
	_yMin = (_monitor.getSize().y / 2.0f) - (_tileSize * _scale * _size.second / 2.0f);
	initWater();
	_water->display();
	update();
}

void	Map::initWater()
{
	sf::Sprite	sprite(_texture, sf::IntRect(32, 104, 32, 32));
	sf::Vector2f	size = _monitor.getSize();

	if (!_water->create(size.x, size.y))
		throw std::logic_error("Can't create the world! (water)");
	_water->clear(sf::Color(0, 0, 0, 0));
	sprite.setScale(_scale, _scale);
	for (int y = 0; y < size.y; y = y + (_scale * _tileSize)) {
		for (int x = 0; x < size.x; x = x + (_scale * _tileSize)) {
			sprite.setPosition(x, y);
			_water->draw(sprite);
		}
	}
}

void	Map::initGround()
{
	sf::Sprite	sprite(_texture, sf::IntRect(0, 104, 32, 32));
	int		pos[2];

	sprite.setScale(_scale, _scale);
	if (!_ground->create((_size.first + 1) * _tileSize * _scale, 
	(_size.second + 1) * _tileSize * _scale))
		throw std::logic_error("Can't create the world! (ground)");
	_ground->clear(sf::Color(0, 0, 0, 0));
	for (std::size_t y = 0; y < _size.second; y++) {
		pos[1] = y * _tileSize * _scale;
		for (std::size_t x = 0; x < _size.first; x++) {
			pos[0] = x * _tileSize * _scale;
			sprite.setPosition(pos[0], pos[1]);
			_ground->draw(sprite);
		}
	}
	drawBorder(_size.second * sprite.getTextureRect().height *
		_scale, sprite);
}

void	Map::drawGame()
{
	sf::Sprite	temp;
	int		size = _tileSize * _scale;

	if (!_action->create(_size.first * _tileSize * _scale, 
		_size.second * _tileSize * _scale))
		throw std::logic_error("Can't create the world! (game)");
	_action->clear(sf::Color(0, 0, 0, 0));
	if (_map.empty())
		return ;
	for_each(_map.begin(), _map.end(), [&](auto data) {
		if (data.second.empty())
			return ;
		for_each(data.second.begin(), data.second.end(), 
		[&](auto elem) {
			temp = elem->draw();
			temp.setPosition(sf::Vector2f(data.first.first *
			size + (std::rand() % (size)), data.first.second * size + (std::rand() % size)));
			_action->draw(temp);
		});
	});
	_action->display();
}

void	Map::drawBorder(int posY, sf::Sprite &sprite)
{
	int	posX;

	sprite.setTextureRect(sf::IntRect(0, 136, 32, 8));
	for (std::size_t x = 0; x < _size.first; x++) {
		posX = x * _tileSize * _scale;
		sprite.setPosition(posX, posY);
		_ground->draw(sprite);
	}
}

std::vector<IObject*>	Map::getObjectsOn(std::pair<std::size_t, std::size_t> pos)
{
	if (_map.empty())
		return std::vector<IObject *>();
	if (_map.find(pos) == _map.end())
		return std::vector<IObject *>();
	return _map[pos];
}


void	Map::initRessources(std::pair<std::size_t, std::size_t> pos,
				std::vector<std::size_t> quantity)
{
	for (std::size_t i = sizeObjectsByType(pos, Type::FOOD);
		i < quantity[0]; i++)
		putObjectOn(new Food(_monitor), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::LINEMATE);
		i < quantity[1]; i++)
		putObjectOn(new Gem(_monitor, GemKind::LINEMATE), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::DERAUMERE);
		i < quantity[2]; i++)
		putObjectOn(new Gem(_monitor, GemKind::DERAUMERE), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::SIBUR);
		i < quantity[3]; i++)
		putObjectOn(new Gem(_monitor, GemKind::SIBUR), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::MENDIANE);
		i < quantity[4]; i++)
		putObjectOn(new Gem(_monitor, GemKind::MENDIANE), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::PHIRAS);
		i < quantity[5]; i++)
		putObjectOn(new Gem(_monitor, GemKind::PHIRAS), pos);
	for (std::size_t i = sizeGemsByKind(pos, GemKind::THYSTAME);
		i < quantity[6]; i++)
		putObjectOn(new Gem(_monitor, GemKind::THYSTAME), pos);
}

std::size_t	Map::sizeObjectsByType(std::pair<std::size_t, std::size_t> pos, Type type)
{
	std::size_t	i = 0;

	if (_map.empty())
		return i;
	if (_map.find(pos) == _map.end())
		return i;
	for (auto it = _map[pos].begin(); it != _map[pos].end(); it++) {
		if ((*it)->getType() == type)
			i++;
	}
	return i;
}

std::size_t	Map::sizeGemsByKind(std::pair<std::size_t, std::size_t> pos, GemKind type)
{
	std::size_t	i = 0;
	Gem		*tmp;

	if (_map.empty())
		return i;
	if (_map.find(pos) == _map.end())
		return i;
	for (auto it = _map[pos].begin(); it != _map[pos].end(); it++) {
		if ((*it)->getType() == Type::GEM) {
			tmp = dynamic_cast<Gem *>(*it);
			if (tmp->getGemKind() == type)
				i++;
		}
	}
	return i;
}

Player	*Map::getPlayerById(int id)
{
	Player	*player = nullptr;

	if (_map.empty())
		return nullptr;
	for (auto it = _map.begin();it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin();
			it2 != (*it).second.end(); it2++) {
			if ((*it2)->getType() != Type::PLAYER)
				continue ;
			player = dynamic_cast<Player *>(*it2);
			if (!player)
				return nullptr;
			if (player->getId() == id)
				return player;
		}
	}
	return nullptr;
}

void	Map::setIncantationResult(std::pair<std::size_t, std::size_t> pos, int result)
{
	std::vector<IObject *> objs = getObjectsOn(pos);
	Player	*tmp;

	if (objs.empty())
		return ;
	for (auto it = objs.begin(); it != objs.end(); it++) {
		if ((*it)->getType() != Type::PLAYER)
			continue ;
		tmp = dynamic_cast<Player *>(*it);
		if (!tmp)
			return ;
		tmp->incante(false);
		tmp->setLevel(tmp->getLevel() + result);
	}
}

Egg	*Map::getEggById(int id)
{
	Egg	*egg = nullptr;

	if (_map.empty())
		return nullptr;
	for (auto it = _map.begin();it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin();
			it2 != (*it).second.end(); it2++) {
			if ((*it2)->getType() != Type::EGG)
				continue ;
			egg = dynamic_cast<Egg *>(*it2);
			if (!egg)
				return nullptr;
			if (egg->getId() == id)
				return egg;
		}
	}
	return nullptr;
}

std::pair<std::size_t, std::size_t>	Map::getEggPosById(int id)
{
	Egg	*egg;

	if (_map.empty())
		return _size;
	for (auto it = _map.begin();it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin();
			it2 != (*it).second.end(); it2++) {
			if ((*it2)->getType() != Type::EGG)
				continue ;
			egg = dynamic_cast<Egg *>(*it2);
			if (!egg)
				return _size;
			if (egg->getId() == id)
				return (*it).first;
		}
	}
	return _size;
}

std::pair<std::size_t, std::size_t>	Map::getPlayerPosById(int id)
{
	Player	*player;

	if (_map.empty())
		return _size;
	for (auto it = _map.begin();it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin();
			it2 != (*it).second.end(); it2++) {
			if ((*it2)->getType() != Type::PLAYER)
				continue ;
			player = dynamic_cast<Player *>(*it2);
			if (!player)
				return _size;
			if (player->getId() == id)
				return (*it).first;
		}
	}
	return _size;
}

void	Map::addTeamName(const std::string teamName)
{
	_teamsName.push_back(teamName);
}

std::vector<std::string>	Map::getTeamsName() const
{
	return _teamsName;
}

bool	Map::isTeamName(const std::string teamName) const
{
	for (auto it = _teamsName.begin(); it != _teamsName.end(); it++) {
		if ((*it) == teamName)
			return true;
	}
	return false;
}

void	Map::putObjectOn(IObject *object, std::pair<std::size_t, std::size_t> pos)
{
	if (pos > _size)
		return ;
	if (_map.find(pos) == _map.end()) {
		_map.insert(
			std::pair<std::pair<std::size_t, std::size_t>,
			std::vector<IObject *>>(pos, std::vector<IObject *>())
		);
	}
	_map[pos].push_back(object);
	drawGame();
	_action->display();
}

void	Map::removeObject(IObject *object)
{
	if (_map.empty())
		return ;
	for (auto it = _map.begin(); it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin();
			it2 != (*it).second.end(); it2++) {
			if (object == (*it2)) {
				(*it).second.erase(it2);
				return ;
			}
		}
	}
}

IObject	*Map::getGemOn(GemKind gem, std::pair<std::size_t, std::size_t> pos)
{
	Gem	*tmp;

	if (_map.find(pos) == _map.end())
		return nullptr;
	for (auto it = _map[pos].begin(); it != _map[pos].end(); it++) {
		if ((*it)->getType() != Type::GEM)
			continue ;
		tmp = dynamic_cast<Gem *>(*it);
		if (!tmp)
			return nullptr;
		if (tmp->getGemKind() != gem)
			return nullptr;
		removeObject(*it);
		return *it;
	}
	return nullptr;
}

IObject *Map::getFoodOn(std::pair<std::size_t, std::size_t> pos)
{
	if (_map.find(pos) == _map.end())
		return nullptr;
	for (auto it = _map[pos].begin(); it != _map[pos].end(); it++) {
		if ((*it)->getType() != Type::FOOD)
			continue ;
		removeObject(*it);
		return *it;
	}
	return nullptr;
}

IObject	*Map::collectObjectOnMap(int res, std::pair<std::size_t, std::size_t> pos)
{
	if (res == 0)
		return getFoodOn(pos);
	if (res >= 1 && res <= 6)
		return getGemOn(static_cast<GemKind>(res - 1), pos);
	return nullptr;
}

void	Map::moveObject(IObject *object, std::pair<std::size_t, std::size_t> pos)
{
	removeObject(object);
	putObjectOn(object, pos);
}

void	Map::setMapSize(std::size_t width, std::size_t height)
{
	_size = std::make_pair(width, height);
	_teamsName = std::vector<std::string>();
	_map.clear();
	initGround();
	_ground->display();
	resize();
}

void	Map::onEvent(const sf::Event &event)
{
	if (event.type == sf::Event::MouseWheelScrolled) {
		if ((_scale > 10.0f && event.mouseWheelScroll.delta == 1) ||
			(_scale < 1.0f && event.mouseWheelScroll.delta == -1))
			return ;
		_scale += (event.mouseWheelScroll.delta / 2.0f);
		drawGame();
		_action->display();
		initGround();
		_ground->display();
		resize();
	}
	else if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left)
			_xMin += std::ceil(_scale);
		else if (event.key.code == sf::Keyboard::Right)
			_xMin -= std::ceil(_scale);
		else if (event.key.code == sf::Keyboard::Down)
			_yMin -= std::ceil(_scale);
		else if (event.key.code == sf::Keyboard::Up)
			_yMin += std::ceil(_scale);
	}
}

std::pair<std::size_t, std::size_t>	Map::getMapSize() const
{
	return _size;
}

std::vector<std::size_t>	Map::getListPlayer()
{
	std::vector<std::size_t>	list{};
	Player				*tmp;

	if (_map.empty())
		return list;
	for (auto it = _map.begin(); it != _map.end(); it++) {
		for (auto it2 = (*it).second.begin(); it2 != 
			(*it).second.end(); it2++) {
			if ((*it2)->getType() == Type::PLAYER) {
				tmp = dynamic_cast<Player *>(*it2);
				if (!tmp)
					return list;
				list.push_back(tmp->getId());
			}
		}
	}
	return list;
}

void	Map::update()
{
	auto	wSprite = sf::Sprite(_water->getTexture());
	auto	gSprite = sf::Sprite(_ground->getTexture());
	sf::Sprite 	aSprite;
	std::vector<std::size_t>	list_id = getListPlayer();

	for (std::size_t i = 0; i < list_id.size(); i++)
		_monitor.getNetwork().requestPlayerPosition(list_id[i]);
	aSprite = sf::Sprite(_action->getTexture());
	aSprite.setPosition(sf::Vector2f(_xMin, _yMin));
	gSprite.setPosition(sf::Vector2f(_xMin, _yMin));
	_monitor.draw(wSprite);
	_monitor.draw(gSprite);
	_monitor.draw(aSprite);
}