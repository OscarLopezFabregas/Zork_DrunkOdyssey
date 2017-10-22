#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
class Item;

class Player{
public:
	Player(int position);
	~Player();
	void Tokenize(const string& line, vector<string>& arguments);
	

	
public:
	int position;
};