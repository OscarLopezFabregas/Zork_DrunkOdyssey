#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


class Npc {
public:
	Npc(const char* name, int position,  const char* dialogue1, const char* dialogue2, const char* description, bool talk1, const char* itemwanted);
	~Npc();
	
	void Look();

public:
	int position;
	const char* name;
	const char* dialogue1;
	const char* dialogue2;
	const char* itemwanted;
	bool talk1;
	
private:
	const char* description;
};