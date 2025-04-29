#include "constant.h"

HMODULE hModule = GetModuleHandle(nullptr);
uintptr_t exeBaseAdress = (uintptr_t)GetModuleHandle(nullptr);

extern Player* localPlayerPtr = *(Player**)(exeBaseAdress + 0x17E0A8);

uintptr_t playersAdress = exeBaseAdress + 0x0018AC04;
extern EntityList* players = (EntityList*)playersAdress;

extern int numPlayers = *(int*)(exeBaseAdress + 0x191FD4);