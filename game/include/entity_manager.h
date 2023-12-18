#pragma once
#include<vector>
#include<map>
#include "entity.h"

typedef std::vector<Entity*> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
private:
	EntityVec _entities;
	EntityMap _entityMap;
	size_t _totalEntities = 0;

public:
	Entity& addEntity(const std::string& tag);
	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);
};
