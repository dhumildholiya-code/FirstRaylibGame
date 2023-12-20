#include "map/map.h"

Tile::Tile(Rectangle srcRectIn, const std::string& nameIn)
	:
	srcRect(srcRectIn),
	name(nameIn)
{
}

int Tile::GetId()
{
	return _id;
}

void Map::AddTile(Rectangle srcRect, const std::string& name)
{
	Tile tile = Tile(srcRect, name);
	tile._id = _tiles.size();
	_tiles.push_back(tile);
}

void Map::Serialize()
{
	std::fstream file;
	file.open(path, std::ios::out);
	if (file)
	{
		file << _tiles.size() << std::endl;
		for (size_t i = 0; i < _tiles.size(); i++)
		{
			file << _tiles[i].GetId() << " " << _tiles[i].srcRect.x << " " << _tiles[i].srcRect.y << " "
				<< _tiles[i].srcRect.width << " " << _tiles[i].srcRect.height << " " << _tiles[i].name.c_str() << std::endl;
		}

		file.close();
	}
}

void Map::Deserialize()
{
	std::fstream file;
	file.open(path, std::ios::in);

	if (file)
	{
		int tileCount;
		Tile tile = Tile(Rectangle{ 0,0,0,0 }, "");
		file >> tileCount;

		for (size_t i = 0; i < tileCount; i++)
		{
			file >> tile._id >> tile.srcRect.x >> tile.srcRect.y >> tile.srcRect.width
				>> tile.srcRect.height >> tile.name;

			_tiles.push_back(tile);
		}
	}
}

void Map::Print()
{
	std::cout << "Tiles In Map : " << std::endl;
	for (size_t i = 0; i < _tiles.size(); i++)
	{
		std::cout << _tiles[i].name << std::endl;
	}
	std::cout << "Tiles End in Map" << std::endl;
}
