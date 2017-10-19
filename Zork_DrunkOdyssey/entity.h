#pragma once
//dont know....
#include <list>

using namespace std;

class Entity {
public:

	Entity();
	~Entity();


public:
	list<Entity> container;
};