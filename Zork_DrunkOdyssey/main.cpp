#include <iostream>
#include <string>
#include "player.h"
#include <stdio.h>
#include "room.h"
#include "world.h"

using namespace std;
Player myplayer;
World myworld;



int main() {
	string playerInput;
	vector<string> args;
	

	cout << "**Welcome to Zork: The Drunk Oddissey**" << endl;
	cout << "----------------------------------------" << endl;
	
	cout << "You just finished  the last drink, the bar is about to close and you should go back home." << endl;
	cout << "The problem is that now, the drinking is hitting hard... " << endl;
	cout << "Your girlfriend is so mad at you, your life is in extrem danger if you the move the dumbass out of the bar and go home." << endl;
	cout << "----------------------------------------" << endl;

	cout << "What are you gonna do?"<<endl;
	cout << ">";
	getline(cin, playerInput);
	myplayer.Tokenize(playerInput, args);
	
	if (args[0] == "look") 
	{
		myworld.Look(args);
	}

	system("pause");
}