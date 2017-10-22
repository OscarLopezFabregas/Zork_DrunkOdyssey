#include "item.h"

Item::Item(const char* name, const char* description, bool taken, int location): name(name), description(description), taken(taken), location(location)
{
}
Item::~Item()
{

}