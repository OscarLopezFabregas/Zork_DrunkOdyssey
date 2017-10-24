#include "item.h"
#include <iostream>

using namespace std;

Item::Item(const char* name, const char* description, int location): name(name), description(description), location(location)
{
}
Item::~Item()
{
	
}
void Item::Look() 
{
	cout << "------------------------------------------------------------------" << endl;
	cout << description << endl;
	cout << "------------------------------------------------------------------" << endl;
}