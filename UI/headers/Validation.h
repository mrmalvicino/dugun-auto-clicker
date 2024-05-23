#pragma once
#include <iostream>
#include "Terminal.h"

class Validation
{
    public:

    int cinIntBetween(int min, int max);

    bool cinBool();

    private:

    Terminal _terminal;
};