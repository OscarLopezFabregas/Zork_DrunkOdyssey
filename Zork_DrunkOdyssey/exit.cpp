#include "room.h"
#include "exit.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, const char* direction): name(name),description(description), origin(origin),destination(destination), direction(direction)
{
}

Exit::~Exit()
{
}
