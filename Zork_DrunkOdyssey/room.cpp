#include "room.h"
#include "item.h"

Room::Room(const char* name, const char* description, int position): name(name), description(description), position(position)// el contenido de "name" es guardado en el const char name,...
{

}

Room::~Room()
{
	delete[] name;
	delete[] description;
}