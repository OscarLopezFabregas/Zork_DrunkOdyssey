#pragma once
#include <vector>
#include <list>
#include "entity.h"
#include "room.h"
#include "player.h"
#include "exit.h"

using namespace std;

class World {

public:
	World();
	~World();

	void Look(const vector<string> args,const int position);
	void Go(const vector<string> args);

public:
	list<Room*> rooms;
	list<Exit*> exits;
	Player* myplayer;
};