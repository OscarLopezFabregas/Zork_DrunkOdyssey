#include "npc.h"

Npc::Npc(const char* name, int position,  const char* dialogue1, const char* dialogue2, const char* description, bool talk1, const char* itemwanted) : name(name), position(position),
dialogue1(dialogue1),dialogue2(dialogue2), description(description), talk1 (talk1), itemwanted(itemwanted)
{

}

Npc::~Npc()
{

}