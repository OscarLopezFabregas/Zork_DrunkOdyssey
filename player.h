#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class World;
class Player{
public:
	Player(int position);
	~Player();
	void Tokenize(const string& line, vector<string>& arguments);
	void ParseCommand(vector<string> args, World* world) const;

	
public:
	int position;
	int life = 3;
};