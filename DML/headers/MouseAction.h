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

    void setCursorPosition(CursorPosition cursorposition);

    CursorEvent getCursorEvent();

    void setCursorEvent(CursorEvent cursorevent);

    private:

    int _time;

    CursorPosition _cursorposition;

    CursorEvent _cursorevent;
};