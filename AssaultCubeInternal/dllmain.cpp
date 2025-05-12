#include <iostream>
#include <windows.h>
#include <string>
#include "constant.h"
#include "genCode.h"
#include "esp.h"

HMODULE hModuleGlobal;

void hook() {
    while (true) {
        ESP::aimbot();
        if (GetAsyncKeyState(VK_END)) break;
        Sleep(10);
    }
    //return 0;
}

DWORD WINAPI console() {
    AllocConsole();
    FILE* f;
    
    freopen_s(&f, "CONOUT$", "w", stdout);
    //freopen_s(&f, "CONIN$", "r", stdin);
    std::cout << "Console Created" << std::endl;
   
    while (true) {
        //system("cls");
        std::string input = "";
        //std::cin >> input;
        if (GetAsyncKeyState(VK_END)) break;
        if (GetAsyncKeyState(VK_UP)) localPlayerPtr->position.z += 0.5;
        if (GetAsyncKeyState(VK_DOWN)) localPlayerPtr->viewAngles.x -= 0.5;
        if (input == "pl")
            std::cout << "number of players" << *numPlayers << std::endl;
        if (input == "ent") {
            for (int i = 0; i < *numPlayers+1; i++) {
                if (players->Players[i] == nullptr)
                    continue;
                    std::cout << "Entity " << i << "Health: " << players->Players[i]->health << std::endl;
            }
        }
        Sleep(50);
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
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)hook, nullptr, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}