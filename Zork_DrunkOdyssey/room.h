#pragma once

class Room {
public:
	Room(const char* name, const char* description,int position);
	~Room();

	const char* name;
	const char* description;
	int position;
};
