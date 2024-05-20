#include "../headers/Click.h"

void Click::left()
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

    #ifdef __linux__
        
    #endif

    #ifdef __APPLE__
        CGPoint cursor;
        cursor = CGEventGetLocation(CGEventCreate(nil));
        CGEventRef clickEvent = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseDown, cursor, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, clickEvent);
        CFRelease(clickEvent);
        clickEvent = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseUp, cursor, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, clickEvent);
        CFRelease(clickEvent);
    #endif
}

void Click::right()
{

}