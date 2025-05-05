#pragma once
#include <Windows.h>
#include "genCode.h"

extern HMODULE hModule;
extern uintptr_t exeBaseAdress;

extern Player* localPlayerPtr;

extern uintptr_t playersAdress;
extern EntityList* players;
extern int* numPlayers;