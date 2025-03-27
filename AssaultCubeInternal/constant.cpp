#include "constant.h"

HMODULE hModule = GetModuleHandle(nullptr);
uintptr_t exeBaseAdress = (uintptr_t)GetModuleHandle(nullptr);

extern Player* localPlayerPtr = *(Player**)(exeBaseAdress + 0x17E0A8);