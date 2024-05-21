#pragma once
#include <string>

class CursorEvent
{
    public:

    CursorEvent();

    int getId();

    void setId(int id);

    std::string getName();

    void setName(std::string name);

    std::string toString();

    private:

    int _id;

    char _name[20];
};