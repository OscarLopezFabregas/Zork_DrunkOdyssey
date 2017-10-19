#pragma once

#include "world.h"
#include "room.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;

World::World() {

	Room* Bar = new Room("Bar", "You find yourself at your beloved smoky bar, at the end of the corridor there is a door with the label <Toilet>");
	Room* Toilet = new Room("Toilet", "The smell of the place almost makes you puke, there is something sparking on the floor...");
	rooms.push_back(Bar);
	rooms.push_back(Toilet);


}

World::~World() {

}

void World::Look(vector<string> args)
{
	for (int i = 0; i < args.size(); i++)
	{
		if (args[i] == "bar")
			
		{
			for (list<Room*>::iterator it = rooms.begin(); it != rooms.cend(); it++)
			{
				if ((*it)->name == "Bar") cout<< (*it)->description<<endl;
			}
			
		}

	}

}