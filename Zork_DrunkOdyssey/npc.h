#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
class Item;

class Npc {
public:
	Npc(int position);
	~Npc();
	


public:
	int position;
	const char* description;
	const char* dialogue;

	//list<Item*> inventory;
};