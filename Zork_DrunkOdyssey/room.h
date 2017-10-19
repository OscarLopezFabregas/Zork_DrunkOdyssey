#pragma once

class Room {
public:
	Room(const char* name, const char* description);
	~Room();

	const char* name;
	const char* description;
};
