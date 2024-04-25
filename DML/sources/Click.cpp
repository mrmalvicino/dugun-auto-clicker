#include "../headers/Click.h"

Click::Click()
{
    setId(0);
    setName("");
}

int Click::getId()
{
    return _id;
}

void Click::setId(int id)
{
    _id = id;
}

std::string Click::getName()
{
    return _name;
}

void Click::setName(std::string name)
{
    strcpy(_name, name.c_str());
}