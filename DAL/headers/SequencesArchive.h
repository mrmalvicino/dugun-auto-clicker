#pragma once
#include <iostream>
#include <cstdio>
#include "../../DML/headers/Sequence.h"

class SequencesArchive
{
    public:

    SequencesArchive();

    SequencesArchive(std::string path);

    void setPath(std::string path);

    std::string getPath();

    bool write(Sequence & reg);

    bool overWrite(Sequence & reg, int index);

    Sequence read(int index);

    int getIndex(int id);

    int getIndex(std::string & name);

    int getRegistersAmount();

    void createEmptyArchive();

    private:

    std::string _path;
};