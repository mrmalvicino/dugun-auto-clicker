#pragma once
#include <iostream>
#include <cstdlib>
#include "Terminal.h"
#include "Validation.h"

class Menu
{
    public:

    void display();

    void run();

    void sequence();

    void file();

    void help();

    void hotkeys();

    void language();

    void about();

    private:

    Terminal _terminal;

    Validation _validation;
};