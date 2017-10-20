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
	Room* Street = new Room("Street", "You feel the cold air of the city freezing your chicks, where the fuck did I put the keys of the car...", 2);
	rooms.push_back(Bar);
	rooms.push_back(Toilet);
	rooms.push_back(Street);
	Exit* BarToilet = new Exit("BarToilet", "You entered the toilet.", Bar, Toilet, "toilet");
	Exit* ToiletBar = new Exit("ToiletBar","You entered the bar.", Toilet, Bar, "bar");
	Exit* BarStreet = new Exit("BarStreet", "You find yourself now outside.", Bar, Street, "street");
	Exit* StreetBar = new Exit("StreetBar", "You went back inside the bar.", Street, Bar, "bar");
	exits.push_back(BarToilet);
	exits.push_back(ToiletBar);
	exits.push_back(BarStreet);
	exits.push_back(StreetBar);
}

World::~World() {

}

void World::Look(const vector<string> args)
{

	for (int i = 0; i < args.size(); i++)
	{
		for (list<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++)
		{
			if ((*it)->position == myplayer->position)
			{
				cout << (*it)->description << endl;
				return;
			}
		}
	}

	cout << "--------------------------" << endl;
	cout << "You cannot see that. Oh man... you cannot look at that, you definately drunk..." << endl;
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
						cout << "--------------------------" << endl;
						cout << (*it2)->description << endl;
						cout << "--------------------------" << endl;
						return;
					}
				}
			}
		}
	}

	cout << "--------------------------" << endl;
	cout << "You cannot go there. Oh man... you cannot look at that, you definately drunk..." << endl;
	cout << "--------------------------" << endl;

}

