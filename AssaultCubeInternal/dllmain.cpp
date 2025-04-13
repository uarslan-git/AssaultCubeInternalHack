#include <iostream>
#include <windows.h>
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
    std::cout << "Console Created" << std::endl;

    while (true) {
        if (GetAsyncKeyState(VK_END)) break;
        if (GetAsyncKeyState(VK_UP)) localPlayerPtr->Position.z += 5;
        if (GetAsyncKeyState(VK_DOWN)) localPlayerPtr->Position.z -= 5;
        //if (input == "print") std::cout << "Local Player Ptr" << localPlayerPtr << std::endl;
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