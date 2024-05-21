#include "../headers/CursorEvent.h"

CursorEvent::CursorEvent()
{
    _id = 1;
    setName("Wait");
}

int CursorEvent::getId()
{
    return _id;
}

void CursorEvent::setId(int id)
{
    _id = id;
}

std::string CursorEvent::getName()
{
    return _name;
}

void CursorEvent::setName(std::string name)
{
    strcpy(_name, name.c_str());
}

std::string CursorEvent::toString()
{
    return _name;
}