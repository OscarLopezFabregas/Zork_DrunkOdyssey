#pragma once

#include "world.h"
#include "player.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "npc.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;

World::World() {
	myplayer = new Player(0);
	
	//List Rooms---
	Room* Bar = new Room("bar", "You find yourself at your beloved smoky bar. Only you and the barman still there, at the end of the corridor there is a door with the label <Toilet>", 0);
	Room* Toilet = new Room("toilet", "The smell of the place almost makes you puke, there is something sparking on the floor...Those are my keys??", 1);
	Room* Street = new Room("street", "You feel the cold air of the city freezing your chicks, Fuck...I cannot drive now...", 2);// HERE!!
	rooms.push_back(Bar);
	rooms.push_back(Toilet);
	rooms.push_back(Street);

	//List Exits---
	Exit* BarToilet = new Exit("BarToilet", "You entered the toilet.", Bar, Toilet, "toilet");
	Exit* ToiletBar = new Exit("ToiletBar","You entered the bar.", Toilet, Bar, "bar");
	Exit* BarStreet = new Exit("BarStreet", "You find yourself now outside.", Bar, Street, "street");
	Exit* StreetBar = new Exit("StreetBar", "You went back inside the bar.", Street, Bar, "bar");
	exits.push_back(BarToilet);
	exits.push_back(ToiletBar);
	exits.push_back(BarStreet);
	exits.push_back(StreetBar);

	//List Items---
	Item* Beer = new Item("beer", "My beer isn't finished yet, I may want it later...", false, 0);
	Item* HomeKeys = new Item("keys", "What the fuck?! How can I forget my keys in this shitty toilet, with them I can go back home", false, 1);
	items.push_back(Beer);
	items.push_back(HomeKeys);

	//List NPC
	Npc* Homeless = new Npc("homeless", 2, "Oh dear folk, I think you shouldn't drive that drunk... What if I give my bike in exchange of the beer you are carrying?", "dialogue2", "description", false);
	Npc* Girlfriend = new Npc("girlfriend", 3, "", "","", false);
	Npc* Barman = new Npc("barman", 0, "Hey man! It is time to close, I'll give a plastic glass so you can take your beer with you!", "", "He looks kinda serious... and I know perfectly about the stick he hides behind the bar...", false);
	npcs.push_back(Homeless);
	npcs.push_back(Girlfriend);
	npcs.push_back(Barman);


}

World::~World() {

}

void World::Look(const vector<string> args)
{
	for (int i = 0; i < args.size(); i++)
	{
		for (list<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++)
		{
			if ((*it)->position == myplayer->position && args[i] == (*it)->name)
			{
				cout << "--------------------------" << endl;
				cout << (*it)->description << endl;
				cout << "--------------------------" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < args.size(); i++)
	{
		for (list<Item*>::iterator it = items.begin(); it != items.end(); it++)
		{
			if ((*it)->location == myplayer->position && args[i] == (*it)->name)
			{
				cout << "--------------------------" << endl;
				cout << (*it)->description << endl;
				cout << "--------------------------" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < args.size(); i++)
	{
		for (list<Npc*>::iterator it = npcs.begin(); it != npcs.end(); it++)
		{
			if ((*it)->position == myplayer->position && args[i] == (*it)->name)
			{
				cout << "--------------------------" << endl;
				cout << (*it)->description << endl;
				cout << "--------------------------" << endl;
				return;
			}
		}
	}

	cout << "--------------------------" << endl;
	cout << "You cannot look at that. Oh man... you definately drunk..." << endl;
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
	cout << "You cannot go there. Oh man... you definately drunk..." << endl;
	cout << "--------------------------" << endl;

}

void World::Take(const vector<string> args)
{

	for (int i = 0; i < args.size(); i++)
	{
		for (list<Item*>::iterator it = items.begin(); it != items.end(); it++)
		{
			if ((*it)->location == myplayer->position && args[i]==(*it)->name && !(*it)->taken)
			{
				
				(*it)->taken = true;
				cout << "--------------------------" << endl;
			    cout << "You have taken the " << (*it)->name << endl;
				cout << "--------------------------" << endl;
				return;

			}
			
			if ((*it)->location == myplayer->position && args[i] == (*it)->name && (*it)->taken)
			{
				cout << "--------------------------" << endl;
				cout << "You have ALREADY taken the " << (*it)->name << endl;
				cout << "--------------------------" << endl;
				return;
			}
		}
	}
	cout << "--------------------------" << endl;
	cout << "You cannot take that. Oh man..., you are definately drunk..." << endl;
	cout << "--------------------------" << endl;

}

void World::Talk (const vector<string> args)
{
	for (int i = 0; i < args.size(); i++)
	{	
		for (list<Npc*>::const_iterator it = npcs.begin(); it != npcs.end(); it++)
		{
			if (args[i] == (*it)->name && myplayer->position == (*it)->position && !(*it)->talk1)
			{
				cout << "--------------------------" << endl;
				cout << (*it)->dialogue1 << endl;
				cout << "--------------------------" << endl;
			}
			if (args[i] == (*it)->name && myplayer->position == (*it)->position && (*it)->talk1) //study if we want the function to act this way...
			{
				cout << "--------------------------" << endl;
				cout << "You already talk to 'that', better not to do so again..." << endl;
				cout << "--------------------------" << endl;
			}
		}
	}
}

void World::Give(const vector<string> args)
{
	for (list<Npc)
}

void World::Inventory()
{
	cout << "--------------------------" << endl;
	for (list<Item*>::const_iterator it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->taken) cout << (*it)->name<<endl;
	}
	cout << "--------------------------" << endl;

}
