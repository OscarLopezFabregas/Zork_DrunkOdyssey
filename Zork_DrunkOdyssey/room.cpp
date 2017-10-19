#include "room.h"

Room::Room(const char* name, const char* description): name(name), description(description) // el contenido de "name" es guardado en el const char name,...
{

}

Room::~Room()
{
	delete[] name;
	delete[] description;
}