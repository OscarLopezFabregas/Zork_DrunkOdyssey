#include "player.h"
#include <list>
#include "world.h"
#include "room.h"
#include "item.h"

using namespace std;
Player::Player(int position) : position(position)
{
}

Player::~Player(){

}

void Player::Tokenize(const string& line, vector<string>& arguments) //method to split a string of multiple words in single words
{

	const char* str = line.c_str(); //declare new pointer variable to the char* that will be equal to line;
	do {
		const char* begin = str;

		while (*str != ' ' && *str) str++;

		arguments.push_back(string(begin, str)); //including a string inside the vector of string "arguments" that starts at begin and finish at str
	} while (0 != *str++); //do while the content of str is different from 0 
}

