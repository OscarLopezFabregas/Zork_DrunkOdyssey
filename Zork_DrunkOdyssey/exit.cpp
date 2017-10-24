#include "room.h"
#include "exit.h"
#include "item.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, const char* direction, Item* itemrequired): name(name),
description(description), origin(origin),destination(destination), direction(direction), itemrequired(itemrequired)
{
}

Exit::~Exit()
{
}
