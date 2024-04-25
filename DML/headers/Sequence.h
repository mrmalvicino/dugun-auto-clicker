#pragma once
#include "MouseAction.h"

class Sequence
{
    public:

    Sequence();

    ~Sequence();

    int getId();

    void setId(int id);

    std::string getName();

    void setName(std::string name);

    int getLoopsAmount();

    void setLoopsAmount(int loopsAmount);

    int getRandomTime();

    void setRandomTime(int randomTime);

    int getRandomPosition();

    void setRandomPosition(int randomPosition);

    MouseAction * getMouseActions();

    void setMouseActions(MouseAction * mouseActions);

    private:

    int _id;

    char _name[30];

    int _loopsAmount;

    int _randomTime;

    int _randomPosition;

    MouseAction * _mouseActions;
};