#include "ConsoleHelper.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

void ConsoleHelper::Init() {
    #ifdef _WIN32
        // Enable UTF-8 and ANSI Escape Codes
        system("chcp 65001 > nul");

        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);

        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);

    // Clear
        system("cls");
    #else
        system("clear");
    #endif

    // Hide Cursor
    std::cout << "\033[?25l";
}

void ConsoleHelper::Clear() {
    // Move Cursor to Home Position
    std::cout << "\033[H";
}