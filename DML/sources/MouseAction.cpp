#include "../headers/MouseAction.h"

MouseAction::MouseAction()
{
    setTime(0);
}

int MouseAction::getTime()
{
    return _time;
}

void MouseAction::setTime(int time)
{
    _time = time;
}

CursorPosition MouseAction::getCursorPosition()
{
    return _cursorposition;
}

void MouseAction::setCursorPosition(CursorPosition cursorposition)
{
    _cursorposition = cursorposition;
}

CursorEvent MouseAction::getCursorEvent()
{
    return _cursorevent;
}

void MouseAction::setCursorEvent(CursorEvent cursorevent)
{
    _cursorevent = cursorevent;
}