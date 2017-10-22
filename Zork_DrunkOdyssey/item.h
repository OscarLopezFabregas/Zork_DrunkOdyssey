#pragma once

class Item {
	
public:
	Item(const char* name, const char* description, bool taken, int location);
	~Item();

public:
	const char* name = nullptr;
	const char* description = nullptr;
	bool taken = false;
	int location;
};