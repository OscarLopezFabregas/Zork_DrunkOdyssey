#pragma once

class Item {
	
public:
	Item(const char* name, const char* description,  int location);
	~Item();
	void Look();
public:
	const char* name = nullptr;
	bool taken = false;
	bool given = false;
	int location;

private:
	const char* description = nullptr;
};