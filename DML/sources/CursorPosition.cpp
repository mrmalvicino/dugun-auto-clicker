#include "../headers/CursorPosition.h"

CursorPosition::CursorPosition()
{
    setX(0);
    setY(0);
}

int CursorPosition::getX()
{
    return _x;
}

void CursorPosition::setX(int x)
{
    _x = x;
}

int CursorPosition::getY()
{
    return _y;
}

void CursorPosition::setY(int y)
{
    _y = y;
}
