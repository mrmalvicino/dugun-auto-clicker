#pragma once
#include <chrono>
#include <thread>

class Timer
{
    public:

    Timer();

    int getInterval();

    void setInterval(int interval);

    int getLoopsAmount();

    void setLoopsAmount(int loopsAmount);

    void start();

    void pause();

    void stop();

    void tick();

    bool enabled(bool isDoWhileCondition = 0);

    private:

    int _interval;

    int _loopsAmount;

    int _loopsDone;

    bool _enabled;

    std::chrono::milliseconds _millisecond;
};