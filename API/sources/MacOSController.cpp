#include "../headers/MacOSController.h"

void MacOSController::leftClick()
{
    #ifdef __APPLE__
        _CGPosition = CGEventGetLocation(CGEventCreate(nullptr));
        _CGEvent = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseDown, _CGPosition, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, _CGEvent);
        CFRelease(_CGEvent);
        _CGEvent = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseUp, _CGPosition, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, _CGEvent);
        CFRelease(_CGEvent);
    #endif
}

void MacOSController::rightClick()
{
    #ifdef __APPLE__
        _CGPosition = CGEventGetLocation(CGEventCreate(nullptr));
        _CGEvent = CGEventCreateMouseEvent(NULL, kCGEventRightMouseDown, _CGPosition, kCGMouseButtonRight);
        CGEventPost(kCGHIDEventTap, _CGEvent);
        CFRelease(_CGEvent);
        _CGEvent = CGEventCreateMouseEvent(NULL, kCGEventRightMouseUp, _CGPosition, kCGMouseButtonRight);
        CGEventPost(kCGHIDEventTap, _CGEvent);
        CFRelease(_CGEvent);
    #endif
}

void MacOSController::move(CursorPosition cursorPosition)
{
    #ifdef __APPLE__
        _CGPosition = CGPointMake(cursorPosition.getX(), cursorPosition.getY());
        _CGEvent = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, _CGPosition, kCGMouseButtonLeft);
        CGEventPost(kCGHIDEventTap, _CGEvent);
        CFRelease(_CGEvent);
    #endif
}

CursorPosition MacOSController::getPosition()
{
    #ifdef __APPLE__
        CursorPosition cursorPosition;
        cursorPosition.setXY(_CGPosition.x, _CGPosition.y);
        return cursorPosition;
    #endif
}