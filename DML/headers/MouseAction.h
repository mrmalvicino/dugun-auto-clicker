#pragma once
#include "CursorPosition.h"
#include "CursorEvent.h"

class MouseAction
{
    public:

    MouseAction();

    int getTime();

    void setTime(int time);

    CursorPosition getCursorPosition();

    void setCursorPosition(CursorPosition cursorPosition);

    CursorEvent getCursorEvent();

    void setCursorEvent(CursorEvent cursorEvent);

    std::string toString();

    private:

    int _time;

    CursorPosition _cursorPosition;

    CursorEvent _cursorEvent;
};