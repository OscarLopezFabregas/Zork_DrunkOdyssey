#pragma once

class Item;

class Room {
public:
	Room(const char* name, const char* description,int position);
	~Room();

	void Look();

public:
	int position;
	const char* name;

private:
	const char* description;
};
