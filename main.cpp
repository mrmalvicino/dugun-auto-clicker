#include <iostream>
#include "DML/headers/Timer.h"

int main()
{
    Timer timer;
    timer.setLoops(5);
    timer.setInterval(500);
    timer.start();

    while(timer.enabled())
    {
        std::cout << "tic" << "\n";
    }

    return 0;
}