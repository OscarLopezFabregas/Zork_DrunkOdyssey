#include "room.h"
#include "item.h"
#include <iostream>
using namespace std;

Room::Room(const char* name, const char* description, int position): name(name), description(description), position(position)// el contenido de "name" es guardado en el const char name,...
{

}

Room::~Room()
{
}

void Room::Look()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << description<<endl;
	cout << "------------------------------------------------------------------" << endl;
}