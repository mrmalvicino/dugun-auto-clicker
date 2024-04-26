#pragma once

class CursorPosition
{
    public:

    CursorPosition();

    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    private:

    int _x;

    int _y;
};