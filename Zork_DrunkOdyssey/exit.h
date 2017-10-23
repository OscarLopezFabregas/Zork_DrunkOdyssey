#pragma once


class Exit {
public:
	Exit(const char* name, const char* description, Room* origin, Room* destination, const char* direction, Item* itemrequired);
	~Exit();
public:
	const char* name;
	const char* direction;
	const char* description;
	Room* origin;
	Room* destination;
	Item* itemrequired;
};