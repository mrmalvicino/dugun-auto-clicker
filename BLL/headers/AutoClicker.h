#pragma once
#include "../../DML/headers/Timer.h"
#include "../../DML/headers/Sequence.h"
#include "../../API/headers/MacOSController.h"

class AutoClicker
{
    public:

    Sequence getSequence() const;

    void setSequence(const Sequence & sequence);

    void runSequence();

    private:

    Timer _timer;
    Sequence _sequence;
    MacOSController _controller;
};