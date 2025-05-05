#include "constant.h"

HMODULE hModule = GetModuleHandle(nullptr);
uintptr_t exeBaseAdress = (uintptr_t)GetModuleHandle(nullptr);

extern Player* localPlayerPtr = *(Player**)(exeBaseAdress + 0x17E0A8);

//extern uintptr_t playersAdress = ;
extern EntityList* players = *(EntityList**)(exeBaseAdress + 0x18AC04);

extern int* numPlayers = (int*)(exeBaseAdress + 0x191FD4);