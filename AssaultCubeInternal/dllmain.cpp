#include <iostream>
#include <windows.h>
#include <string>
#include "constant.h"
#include "genCode.h"

HMODULE hModuleGlobal;

void hook() {
    FreeLibraryAndExitThread(hModule, 0);
}

DWORD WINAPI console() {
    AllocConsole();
    FILE* f;
    
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONIN$", "r", stdin);
    std::cout << "Console Created" << std::endl;
    

    while (true) {
        std::string input;
        std::cin >> input;
        if (GetAsyncKeyState(VK_END)) break;
        if (GetAsyncKeyState(VK_UP)) localPlayerPtr->position.z += 5;
        if (GetAsyncKeyState(VK_DOWN)) localPlayerPtr->position.z -= 5;
        if (input == "pl")
            std::cout << "number of players" << numPlayers << std::endl;
        if (input == "ent") {
            for (int i = 1; i < numPlayers; i++) {
                if (players->players[i] == nullptr || players->players[i]->vtable == nullptr)
                    break;
                std::cout << "Entrity " << i << "Health: " << players->players[i]->health << std::endl;
            }
        }
        Sleep(1);
    }
    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModuleGlobal, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hModuleGlobal = hModule;
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)console, nullptr, 0, nullptr));
        //CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hook, 0, 0, 0));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}