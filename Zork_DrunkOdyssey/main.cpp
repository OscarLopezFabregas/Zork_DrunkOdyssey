#include <iostream>
#include <string>
#include "player.h"
#include <stdio.h>
#include "room.h"
#include "world.h"

using namespace std;
void intro();
void command(vector<string> args, World* world);
World* myworld = new World();

int main() {
	
	string playerInput;
	vector<string> args;
	
	intro();
	
	while (playerInput != "quit")
	{
		args.clear();
		cout << "What are you gonna do?" << endl;
		cout << ">";
		getline(cin, playerInput);
		myworld->myplayer->Tokenize(playerInput, args);
		command(args, myworld);
	
	}
}

void intro() 
{
	
	cout << "----------------------------------------" << endl;
	cout << "**Welcome to Zork: The Drunk Oddissey**" << endl;
	cout << "----------------------------------------" << endl;

	cout << "You just finished  the last drink, the bar is about to close and you should go back home." << endl;
	cout << "The problem is that now, the drinking is hitting hard... " << endl;
	cout << "Your girlfriend is so mad at you, your life is in extrem danger if you do not move \nthe dumbass out of the bar and go home." << endl;
	cout << "----------------------------------------" << endl;
}
void command(vector<string> args, World* world)
{
	if (args[0] == "look")
	{
		myworld->Look(args);
	}
	if (args[0] == "go")
	{
		myworld->Go(args);
	}
	if (args[0] == "take")
	{
		myworld->Take(args);
	}
	if (args[0] == "talk")
	{
		myworld->Talk(args);
	}
	if (args[0] == "give")
	{
		myworld->Give(args);
	}
	if (args[0] == "inventory")
	{
		myworld->Inventory();
	}
	if (args[0] == "quit")
	{
		return;
	}
}