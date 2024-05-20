#pragma once
#include <chrono>
#include <thread>

class Timer
{
    public:

    Timer();

    int getInterval();

    void setInterval(int interval);

    int getLoops();

    void setLoops(int loops);

    void start();

    void pause();

    void stop();

    bool enabled();

    private:

    int _interval;

    int _loops;

    int _loopsDone;

    bool _enabled;

    std::chrono::milliseconds _millisecond;
};