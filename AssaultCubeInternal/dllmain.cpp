#include <iostream>
#include <windows.h>
#include "constant.h"
#include "genCode.h"

void hook() {
    FreeLibraryAndExitThread(hModule, 0);
}

void console() {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONIN$", "r", stdin);
    std::cout << "Console Created" << std::endl;
    while (true) {
        std::string input;
        std::cin >> input;
        if (GetAsyncKeyState(VK_END)) break;
        if (input == "up") localPlayerPtr->pos.x += 5;
        if (input == "down") localPlayerPtr->pos.x -= 5;
        if (input == "print") std::cout << "Local Player Ptr" << localPlayerPtr << std::endl;
    }
    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)console, 0, 0, 0));
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hook, 0, 0, 0));

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}