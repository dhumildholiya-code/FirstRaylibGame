#pragma once
#include <string>
#include "component.h"

class Entity {
private:
	const size_t _id = 0;
	const std::string _tag = "default";
	bool _alive = true;

public:
	Transform* transform;
	BBox* bbox;
	Sprite* sprite;

public:
	Entity(const std::string& tag, size_t id);
};
