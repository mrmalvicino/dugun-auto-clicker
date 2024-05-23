#pragma once
#include "MouseAction.h"

class Sequence
{
    public:

    Sequence();
/*
    ~Sequence();
*/
    int getId();

    void setId(int id);

    bool getStatus();

    void setStatus(bool status);

    std::string getName();

    void setName(std::string name);

    int getLoopsAmount();

    void setLoopsAmount(int loopsAmount);

    int getRandomTime();

    void setRandomTime(int randomTime);

    int getRandomPosition();

    void setRandomPosition(int randomPosition);

    MouseAction * getMouseActions();

    void setMouseActions(MouseAction * mouseActions, int actionsAmount);

    int getActionsAmount() const;

    private:

    int _id;

    bool _status;

    char _name[30];

    int _loopsAmount;

    int _randomTime;

    int _randomPosition;

    MouseAction * _mouseActions;

    int _actionsAmount;
};