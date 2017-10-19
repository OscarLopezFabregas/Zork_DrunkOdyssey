#pragma once

#include "world.h"
#include "room.h"
#include "exit.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;

World::World() {
	myplayer = new Player(0);
	Room* Bar = new Room("Bar", "You find yourself at your beloved smoky bar, at the end of the corridor there is a door with the label <Toilet>", 0);
	Room* Toilet = new Room("Toilet", "The smell of the place almost makes you puke, there is something sparking on the floor...", 1);
	rooms.push_back(Bar);
	rooms.push_back(Toilet);
	Exit* BarToilet = new Exit("BarToilet", "You entered the toilet", Bar, Toilet, "north");
	Exit* ToiletBar = new Exit("ToiletBar","You entered the bar", Toilet, Bar, "south");
	exits.push_back(BarToilet);

}

World::~World() {

}

void World::Look(const vector<string> args, const int position)
{

	for (int i = 0; i < args.size(); i++)
	{
		if (args[i] == "bar" && position == 0)
			
		{
			for (list<Room*>::iterator it = rooms.begin(); it != rooms.cend(); it++)
			{
				if ((*it)->name == "Bar")
				{
					cout << "--------------------------" << endl;
					cout << (*it)->description << endl;
					cout << "--------------------------" << endl;
					return;
				}
			}	
		}
		else if (args[i] == "toilet" && position == 1)

		{
			for (list<Room*>::iterator it = rooms.begin(); it != rooms.cend(); it++)
			{
				if ((*it)->name == "Toilet")
				{
					cout << "--------------------------" << endl;
					cout << (*it)->description << endl;
					cout << "--------------------------" << endl;
					return;
				}
			}
		}
	}

	cout << "--------------------------" << endl;
	cout << "Oh man... you cannot look at that, you definately drunk..." << endl;
	cout << "--------------------------" << endl;

}

void World::Go(const vector<string> args)
{
	for (int i = 0; i < args.size(); i++)
	{
		for (list<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++)
		{
			if ((*it)->position == myplayer->position)
			{
				for (list<Exit*>::iterator it2 = exits.begin(); it2 != exits.end(); it2++)
				{
					if ((*it2)->origin == (*it) && (*it2)->direction == args[i])
					{
						myplayer->position = (*it2)->destination->position;
						cout << (*it2)->description << endl;
					}
				}
			}
		}
	}
}

