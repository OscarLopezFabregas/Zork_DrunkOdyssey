#pragma once
#include <vector>
#include <list>
#include "entity.h"
#include "room.h"



class Npc;
class Exit;
class Player;

using namespace std;

class World {

public:
	World();
	~World();

	void Look(const vector<string> args);
	void Go(const vector<string> args);
	void Take(const vector<string> args);
	void Talk(const vector<string> args);

public:
	list<Room*> rooms;
	list<Exit*> exits;
	list<Item*> items;
	list<Npc*> npcs;
	Player* myplayer;
};