#pragma once
#include "Position.h"
#include "Click.h"

class MouseAction
{
    public:

    MouseAction();

    int getTime();

    void setTime(int time);

    Position getPosition();

    void setPosition(Position position);

    Click getClick();

    void setClick(Click click);

    private:

    int _time;

    Position _position;

    Click _click;
};