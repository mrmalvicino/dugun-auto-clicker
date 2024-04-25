#include "../headers/Position.h"

Position::Position()
{
    setX(0);
    setY(0);
}

int Position::getX()
{
    return _x;
}

void Position::setX(int x)
{
    _x = x;
}

int Position::getY()
{
    return _y;
}

void Position::setY(int y)
{
    _y = y;
}
