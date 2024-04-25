#pragma once
#include <string>

class Click
{
    public:

    Click();

    int getId();

    void setId(int id);

    std::string getName();

    void setName(std::string name);

    private:

    int _id;

    char _name[20];
};