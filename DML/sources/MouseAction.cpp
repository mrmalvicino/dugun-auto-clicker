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

Position MouseAction::getPosition()
{
    return _position;
}

void MouseAction::setPosition(Position position)
{
    _position = position;
}

Click MouseAction::getClick()
{
    return _click;
}

void MouseAction::setClick(Click click)
{
    _click = click;
}