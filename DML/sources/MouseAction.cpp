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
    return _cursorPosition;
}

void MouseAction::setCursorPosition(CursorPosition cursorPosition)
{
    _cursorPosition = cursorPosition;
}

CursorEvent MouseAction::getCursorEvent()
{
    return _cursorEvent;
}

void MouseAction::setCursorEvent(CursorEvent cursorEvent)
{
    _cursorEvent = cursorEvent;
}