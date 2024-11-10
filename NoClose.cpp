#include <windows.h>
#include <iostream>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()

bool ConsoleHandler(DWORD event) {
    if (event == CTRL_CLOSE_EVENT) {
        // List of specific bug check codes
        int bugCheckCodes[] = { 0xD1, 0x0A, 0xE0, 0x7B, 0xA5, 0xE2, 0xEA, 0x7E, 0xC5 };

        // Seed random number generator
        srand((unsigned)time(0));

        // Select a random bug check code from the array
        int randomIndex = rand() % (sizeof(bugCheckCodes) / sizeof(bugCheckCodes[0]));
        int bugCheckCode = bugCheckCodes[randomIndex];

        // Construct the command to run NMF.exe with the selected bug check code
        char command[100];
        sprintf_s(command, sizeof(command), "C:\\Windows\\Sysnative\\NMF.exe /bugcheck 0x%X", bugCheckCode);

        // Execute the command
        system(command);

        // Returning FALSE allows the console to close
        return FALSE;
    }
    return TRUE;
}

int main() {
    // Seed the random number generator at the start of the program
    srand((unsigned)time(0));

    // Set up the console control handler to catch the close event
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);

    printf("Go ahead, close it... see what happens >:)");

    // Infinite loop to keep the console open
    while (1) {
        Sleep(10);
    }

    return 0;
}
