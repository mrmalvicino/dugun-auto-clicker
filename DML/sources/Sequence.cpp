#include "../headers/Sequence.h"

Sequence::Sequence()
{
    setId(0);
    setName("");
    setLoopsAmount(0);
    setRandomTime(0);
    setRandomPosition(0);
}

Sequence::~Sequence()
{
    delete [] _mouseActions;
}

int Sequence::getId()
{
    return _id;
}

void Sequence::setId(int id)
{
    _id = id;
}

std::string Sequence::getName()
{
    return _name;
}

void Sequence::setName(std::string name)
{
    strcpy(_name, name.c_str());
}

int Sequence::getLoopsAmount()
{
    return _loopsAmount;
}

void Sequence::setLoopsAmount(int loopsAmount)
{
    _loopsAmount = loopsAmount;
}

int Sequence::getRandomTime()
{
    return _randomTime;
}

void Sequence::setRandomTime(int randomTime)
{
    _randomTime = randomTime;
}

int Sequence::getRandomPosition()
{
    return _randomPosition;
}

void Sequence::setRandomPosition(int randomPosition)
{
    _randomPosition = randomPosition;
}

MouseAction * Sequence::getMouseActions()
{
    return _mouseActions;
}

void Sequence::setMouseActions(MouseAction * mouseActions, int size)
{
    _mouseActions = mouseActions;
    _actionsAmount = size;
}

int Sequence::getActionsAmount() const
{
    return _actionsAmount;
}