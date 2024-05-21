#pragma once
#include <string>

class CursorPosition
{
    public:

    CursorPosition();

    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    std::string toString();

    private:

    int _x;

    int _y;
};