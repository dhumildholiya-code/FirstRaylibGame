#pragma once
#include"raylib.h"
#include <iostream>
#include <fstream>
#include<string>
#include <vector>

class Tile
{
	friend class Map;
private: 
	int _id = -1;
public:
	int GetId();
	Rectangle srcRect;
	std::string name;

private:
	Tile(Rectangle srcRectIn, const std::string& nameIn);
};

class Map
{
private:
	const std::string path = "resources/map/tiles.map";
	std::vector<Tile> _tiles;

public:
	void AddTile(Rectangle srcRect, const std::string& name);
	void Serialize();
	void Deserialize();
	void Print();
};
