#pragma once
#include <vector>
#include <list>
#include "entity.h"


class Item;
class Room;
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
	void Give(const vector<string> args);
	void Inventory();
	
public:
	list<Room*> rooms;
	list<Exit*> exits;
	list<Item*> items;
	list<Npc*> npcs;
	Player* myplayer;
};