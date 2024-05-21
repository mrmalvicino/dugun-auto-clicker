#include "../headers/WindowsController.h"

void WindowsController::leftClick()
{
    #ifdef _WIN64
        POINT p;
        GetCursorPos(&p);
        INPUT input;
        input.type = INPUT_MOUSE;
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &input, sizeof(INPUT));
        Sleep(5);
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &input, sizeof(INPUT));
    #endif
}

void WindowsController::rightClick()
{
    #ifdef _WIN64
        POINT p;
        GetCursorPos(&p);
        INPUT input;
        input.type = INPUT_MOUSE;
        input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &input, sizeof(INPUT));
        Sleep(5);
        input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        SendInput(1, &input, sizeof(INPUT));
    #endif
}