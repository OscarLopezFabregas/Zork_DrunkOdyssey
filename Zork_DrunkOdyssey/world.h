#pragma once
#include <vector>
#include <list>
#include "entity.h"
#include "room.h"

using namespace std;

class World {

public:
	World();
	~World();

void Look(vector<string> arguments);

public:
	list<Room*> rooms;
};